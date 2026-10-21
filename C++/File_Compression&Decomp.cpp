#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    char data;
    int freq;
    Node* left;
    Node* right;
};

struct QueueNode{
    Node* treeNode;
    QueueNode* next;
};

Node* makeNode(char c, int f){
    Node* newNode = new Node();
    newNode->data = c;
    newNode->freq = f;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

QueueNode* makeQNode(Node* x){
    QueueNode* newNode = new QueueNode();
    newNode->treeNode = x;
    newNode->next = nullptr;

    return newNode;
}

QueueNode* enqueue(QueueNode* head, Node* n){
    QueueNode* newNode = makeQNode(n);

    if(head == nullptr || head->treeNode->freq > n->freq){
        newNode->next = head;
        return newNode;
    }
    QueueNode* current = head;
    while(current->next != nullptr && current->next->treeNode->freq <= n->freq){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

Node* dequeue(QueueNode*& head){
    Node* deqNode = head->treeNode;
    QueueNode* current = head;
    head = head->next;
    delete current;
    return deqNode;
}

void frequencyCount(char filename[], int frequency[]){
    ifstream inFile(filename);
    if(!inFile){
        cout<<"ERROR OPENING FILE!";
        cin.ignore();
        cin.get();
        return;
    }

    char c;
    while(inFile.get(c)){
        frequency[(unsigned char)c]++;
    }
}

void LeftRight(Node* n, char path[], int depth, char code[][50]){
    if(n == nullptr)
        return;

    if(n->left == nullptr && n->right == nullptr){
        path[depth] = '\0';
        int i = 0;
        while(path[i] != '\0'){
            code[(unsigned char)n->data][i] = path[i];
            i++;
        }
        code[(unsigned char)n->data][i] = '\0';
        return;
    }

    path[depth] = '0';
    LeftRight(n->left, path, depth + 1, code);
    path[depth] = '1';
    LeftRight(n->right, path, depth + 1, code);
}

int encodeText(char filename[], char codes[][50], int totalBits, int frequency[]){
    ifstream inFile(filename);
    if(!inFile){
        cout<<"ERROR OPENING FILE!";
        cin.get();
        return 0;
    }

    char c;
    int byte = 0, bitCount = 0;

    ofstream outFile("compressed.bin", ios::binary);
    outFile.write((char*)&totalBits, sizeof(totalBits));
    int distinct = 0;
    for(int i = 0; i <= 255; i++){
        if(frequency[i] > 0){
            distinct++;
        }
    }
    outFile.write((char*)&distinct, sizeof(distinct));
    for(int i = 0; i <= 255; i++){
        if(frequency[i] > 0){
            char ch = (char)i;
            outFile.write(&ch, 1);
            outFile.write((char*)&frequency[i], sizeof(int));
        }
    }
    while(inFile.get(c)){
        int len = 0;
        while(codes[(unsigned char)c][len] != '\0'){
            byte = byte * 2;
            if(codes[(unsigned char)c][len] == '1'){
                byte++;
            }
            bitCount++;
            if(bitCount == 8){
                outFile.put((char)byte);
                byte = 0;
                bitCount = 0;
            }
            len++;
        }
    }
    if(bitCount > 0){
        while(bitCount < 8){
            byte = byte * 2;
            bitCount++;
        }
        outFile.put((char)byte);
    }
    return totalBits;
}

class Compression{

};

int main(){
    int frequency[256] = {0};
    char filename[100];
    cin>>filename;
    frequencyCount(filename, frequency);
    int originalSize = 0;
    for(int i = 0; i <= 255; i++){
        originalSize += frequency[i];
    }
    for(int i = 0; i < 256; i++){
        if(frequency[i] == 0)
            continue;

        if(i == '\n'){
            cout<<"Newline: ";
        }
        else if(i == ' '){
            cout<<"Space: ";
        }
        else if(i == '\t'){
            cout<<"Tab: ";
        }
        else{
            cout<<(char)i<<": ";
        }
        cout<<frequency[i]<<endl;
    }
    QueueNode* head = nullptr;

    for(int i = 0; i <= 255; i++){
        if(frequency[i] > 0){
            Node* newNode = makeNode((char)i, frequency[i]);
            head = enqueue(head, newNode);
        }
    }
    while(head->next != nullptr){
        Node* left = dequeue(head);
        Node* right = dequeue(head);
        Node* newNode = makeNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        head = enqueue(head, newNode);
    }
    Node* root = head->treeNode;
    char codes[256][50] = {0};
    char path[50];
    LeftRight(root, path, 0, codes);
    int totalBits = 0;
    for(int i = 0; i <= 255; i++){
        if(codes[i][0] != '\0'){
            int len = 0;
            while(codes[i][len] != '\0'){
                len++;
            }
            totalBits += frequency[i] * len;
        }
    }
    for(int i = 0; i <= 255; i++){
        if(codes[i][0] != '\0'){
            cout<<(char)i<<": "<<codes[i]<<endl;
        }
    }

    cout<<encodeText(filename, codes, totalBits, frequency);

    ifstream inFile("compressed.bin", ios::binary);
    int compressedSize = 0;
    char ch;
    while(inFile.get(ch)){
        compressedSize++;
    }

    double saved = (originalSize - compressedSize) * 100.0 / originalSize;
    cout<<endl<<"Original Size: "<<originalSize<<" bytes";
    cout<<endl<<"Compressed Size: "<<compressedSize<<" bytes";
    cout<<endl<<"Space saved: "<<saved<<"%";

    
    return 0;
}