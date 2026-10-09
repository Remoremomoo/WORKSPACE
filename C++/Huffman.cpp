#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    char data;
    int freq;
    Node* left;
    Node* right;
};

//READ A TEXT FILE AND DISPLAY THE FREQUENCIES OF CHARACTERS
int main(){
    int frequency[256] = {0};
    ifstream inFile("Huffman.cpp");
    if(!inFile){
        cout<<"ERROR OPENING FILE";
        return 1;
    }
    char c;
    while(inFile.get(c)){
        frequency[c]++;

        if(c == '\n')
            cout<<"NewLine: ";

        if(c == ' ')
            cout<<"Space: ";

        if(c == '\t')
            cout<<"Tab: ";

        else
            cout<<c<<": ";
        
        cout<<frequency[c]<<endl;
    }

    return 0;
}