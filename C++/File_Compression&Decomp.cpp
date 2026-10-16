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

void frequencyCount(char filename[], int frequency[]){
    ifstream inFile(filename);
    if(!inFile){
        cout<<"ERROR OPENING FILE!";
        cin.get();
        return;
    }

    char c;
    while(inFile.get(c)){
        frequency[(unsigned char)c]++;
    }
}

class Compression{

};

int main(){
    int frequency[256] = {0};
    char filename[100];
    cin>>filename;
    frequencyCount(filename, frequency);

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
    
    return 0;
}