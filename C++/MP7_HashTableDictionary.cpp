#include <iostream>
#include <stdlib.h>
#include <limits>
#define SIZE 10
using namespace std;

class HashTable{
    private:
    struct Node{
        int key;
        Node* next;
        Node(int key){
            next = nullptr;
            this->key = key;
        }
    };
    Node* table[SIZE];
    int hashFunction(int key);

    public:
    HashTable(){
        for(int i = 0; i < SIZE; i++){
            table[i] = nullptr;
        }
    }
    void insertKey(int key);
    void display();
    void searchKey(int key);
    void deleteKey(int key);
};

int HashTable :: hashFunction(int key){
    return key % SIZE;
}

void HashTable :: insertKey(int key){
    system("cls");
    if(key < 0){
        cout<<"Invalid Key!"<<endl<<endl;
        cout<<"Press to go back...";
        cin.ignore();
        cin.get();
        return;
    }
    int index = hashFunction(key);
    Node* current = table[index];

    while(current != nullptr){
        if(current->key == key){
            cout<<"DUPLICATE!"<<endl<<endl<<"Please enter to go back...";
            cin.ignore();
            cin.get();
            return;
        }
        current = current->next;
    }
    Node* newNode = new Node(key);
    newNode->next = table[index];
    table[index] = newNode;

    cout<<"Inserted at index "<<index;
    cout<<endl<<endl<<"Press to continue...";
    cin.ignore();
    cin.get();
}

void HashTable :: display(){
    system("cls");
    for(int i = 0; i <= SIZE - 1; i++){
        Node* current = table[i];
        cout<<i<<": ";
        while(current != nullptr){
            cout<<current->key<<" -> ";
            current = current->next;
        }
        cout<<"NULL"<<endl;
    }
    cout<<endl<<endl<<"Press to continue...";
    cin.ignore();
    cin.get();
}

void HashTable :: searchKey(int key){
    system("cls");
    if(key < 0){
        cout<<"Invalid Key!"<<endl<<endl;
        cout<<"Press to go back...";
        cin.ignore();
        cin.get();
        return;
    }
    int index = hashFunction(key);
    Node* current = table[index];
    while(current != nullptr){
        if(current->key == key){
            cout<<"Key found at index "<<index;
            cout<<endl<<endl<<"Press to continue...";
            cin.ignore();
            cin.get();
            return;
        }
        current = current->next;
    }
    cout<<endl<<"Key not found!"<<endl<<endl;
    cout<<"Press to go back...";
    cin.ignore();
    cin.get();
}

void HashTable :: deleteKey(int key){
    system("cls");
    if(key < 0){
        cout<<"Invalid Key!"<<endl<<endl;
        cout<<"Press to go back...";
        cin.ignore();
        cin.get();
        return;
    }
    int index = hashFunction(key);
    Node* current = table[index];
    Node* prev = nullptr;

    while(current != nullptr){
        if(current->key == key){
            if(prev == nullptr){
                table[index] = current->next;
            }
            else{
                prev->next = current->next;
            }
            delete current;
            cout<<"Key deleted from index "<<index<<endl<<endl;
            cout<<"Press to go back...";
            cin.ignore();
            cin.get();
            return;
        }

        prev = current;
        current = current->next;
    }
    cout<<"Key not found!"<<endl<<endl;
    cout<<"Press to go back...";
    cin.ignore();
    cin.get();
}

int menu(){
    system("cls");
    cout<<"Hash Table Dictionary"<<endl<<endl;
    cout<<"1. Insert Key"<<endl<<"2. Search Key"<<endl<<"3. Delete Key"<<endl<<"4. Display Table"<<endl<<"5. Exit"<<endl<<endl;
    cout<<"Choose [1-5]: ";
    int choice;
    cin>>choice;

    return choice;
}

int main(){
    HashTable h;
    int key;
    bool isRunning = true;
    
    while(isRunning){
        switch(menu()){
            case 1:
            cout<<"Enter key to insert: ";
            cin>>key;
            h.insertKey(key);
            break;

            case 2:
            cout<<"Enter key to search: ";
            cin>>key;
            h.searchKey(key);
            break;

            case 3:
            cout<<"Enter key to delete: ";
            cin>>key;
            h.deleteKey(key);
            break;

            case 4:
            h.display();
            break;

            case 5:
            cout<<"Closing...";
            cin.ignore();
            cin.get();
            isRunning = false;
            break;

            default:
            cout<<"Invalid Choice!";
            cout<<endl<<endl<<"Press to go back...";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        }
    }
}