#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#define MAX 5
using namespace std;

struct Digit{
    int num;
    Digit* next;
};

class Circular{
    private:
    int s1[MAX];
    int f = -1, r = -1, ctr = 0;
    bool isfull();
    bool isempty();

    public:
    void enqueue(int n);
    void dequeue();
    void display();
    void menu();
};

bool Circular :: isfull(){
    return ctr == MAX;
}
bool Circular :: isempty(){
    return ctr == 0;
}
void Circular :: enqueue(int n){
    system("cls");
    if(isfull()){
        cout<<"QUEUE IS FULL"<<endl<<endl;
        system("pause");
        return;
    }
    if(f == -1){
        f++;
        r++;
        s1[f] = n;
        ctr++;
        cout<<"ENQUEUED!"<<endl<<endl;
        system("pause");
        return;
    }
    r = (r + 1) % MAX;
    s1[r] = n;
    ctr++;
    cout<<"ENQUEUED!"<<endl<<endl;
    system("pause");
    return;
}
void Circular :: dequeue(){
    system("cls");
    if(isempty()){
        cout<<"QUEUE IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    f = (f + 1) % MAX;
    ctr--;
    cout<<"DEQUEUED!"<<endl<<endl;
    system("pause");
    return;
}
void Circular :: display(){
    system("cls");
    if(isempty()){
        cout<<"QUEUE IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    cout<<"QUEUE LIST: "<<endl<<endl;
    int temp = f, j = 0;
    while(j != ctr){
        cout<<s1[temp]<<endl;
        temp = (temp + 1) % MAX;
        j++;
    }
    system("pause");
    return;
}
void Circular :: menu(){
    int choice;
    bool running = true;

    while(running){
        system("cls");
        int choice;
        cout<<"ARRAY CIRCULAR QUEUE"<<endl<<endl;
        cout<<"ACTION TOOLS: "<<endl<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl<<endl;
        cout<<"Choose [1-4]: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            int input;
            cout<<endl<<endl<<"Enter Number: ";
            cin>>input;
            cin.ignore();
            enqueue(input);
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            running = false;
            cout<<endl<<endl<<"Returning...";
            Sleep(1000);
            break;

            default:
            cout<<endl<<endl<<"INVALID INPUT!"<<endl<<endl;
            system("pause");
            break;
        }
    }
}

class linkedQueue{
    private:
    Digit* f = nullptr;
    Digit* r = nullptr;
    bool isempty();

    public:
    void lEnqueue(int n);
    void lDequeue();
    void lDisplay();
    void lMenu();
};

bool linkedQueue :: isempty(){
    return f == nullptr;
}
void linkedQueue :: lEnqueue(int n){
    system("cls");
    Digit* newNode = new Digit(n, nullptr);

    if(f == nullptr){
        f = newNode;
        r = newNode;
        return;
    }
    Digit* temp = r;
    r = newNode;
    temp->next = r;
    cout<<"ENQUEUED!"<<endl<<endl;
    system("pause");
    return;
}
void linkedQueue :: lDequeue(){
    system("cls");
    if(isempty()){
        cout<<"QUEUE IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    if(f->next == nullptr){
        delete f;
        f = nullptr;
        r = nullptr;
        cout<<"DEQUEUED!"<<endl<<endl;
        system("pause");
        return;
    }
    Digit* temp = f;
    f = temp->next;
    delete temp;
    cout<<"DEQUEUED!"<<endl<<endl;
    system("pause");
    return;
}
void linkedQueue :: lDisplay(){
    system("cls");
    if(isempty()){
        cout<<"QUEUE IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    cout<<"LINKED LIST QUEUE:"<<endl<<endl;
    Digit* temp = f;
    while(temp != nullptr){
        cout<<temp->num<<endl;
        temp = temp->next;
    }
    system("pause");
    return;
}
void linkedQueue :: lMenu(){
    int choice;
    bool running = true;

    while(running){
        system("cls");
        int choice;
        cout<<"LINKED LIST CIRCULAR QUEUE"<<endl<<endl;
        cout<<"ACTION TOOLS: "<<endl<<"1. Enqueue"<<endl<<"2. Dequeue"<<endl<<"3. Display"<<endl<<"4. Exit"<<endl<<endl;
        cout<<"Choose [1-4]: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            int input;
            cout<<endl<<endl<<"Enter Number: ";
            cin>>input;
            cin.ignore();
            lEnqueue(input);
            break;

            case 2:
            lDequeue();
            break;

            case 3:
            lDisplay();
            break;

            case 4:
            running = false;
            cout<<endl<<endl<<"Returning...";
            Sleep(1000);
            break;

            default:
            cout<<endl<<endl<<"INVALID INPUT!"<<endl<<endl;
            system("pause");
            break;
        }
    }
}

int main(){
    Circular c;
    linkedQueue l;
    int input;
    bool running = true;

    while(running){
        system("cls");
        int choice;
        cout<<"CIRCULAR LIST"<<endl<<endl;
        cout<<"MODES:"<<endl<<"1. Array Circular Queue"<<endl<<"2. Linked List Circular Queue"<<endl<<"3. Exit"<<endl<<endl;
        cout<<"Choose [1-3]: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            c.menu();
            break;

            case 2:
            l.lMenu();
            break;

            case 3:
            running = false;
            cout<<endl<<endl<<"Thank you for using!";
            Sleep(1000);
            break;

            default:
            cout<<endl<<endl<<"INVALID INPUT!";
            Sleep(3000);
            break;
        }
    }
}