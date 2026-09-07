#include <iostream>
#include <iomanip>
#include <stdlib.h>
#define MAX 5
using namespace std;

struct Digit{
    int num;
    Digit* next;
};

class Array{
    private:
    int s1[MAX];
    int top = MAX;
    bool isfull();
    bool isempty();

    public:
    void push(int n);
    void pop();
    void topDisplay();
    void display();
    void uiArray();
};
bool Array :: isfull(){
    return top == 0;
}
bool Array :: isempty(){
    return top == MAX;
}
void Array :: push(int n){
    system("cls");
    if(isfull()){
        cout<<"Stack Overflow!"<<endl<<endl;
        system("pause");
        return;
    }
    top--;
    s1[top] = n;
    cout<<"Number Added!"<<endl<<endl;
    system("pause");
    return;
}
void Array :: pop(){
    system("cls");
    if(isempty()){
        cout<<"Stack Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    top++;
    cout<<"Top Popped!"<<endl<<endl;
    system("pause");
    return;
}
void Array :: topDisplay(){
    if(isempty()){
        cout<<"Stack Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    cout<<"Top: "<<s1[top]<<endl<<endl;
    system("pause");
    return;
}
void Array :: display(){
    if(isempty()){
        cout<<"Stack Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    cout<<"Stack List: "<<endl<<endl;
    for(int i = top; i <= MAX - 1; i++){
        cout<<s1[i]<<endl;
    }
    cout<<endl;
    system("pause");
    return;
}
void Array :: uiArray(){
    bool stillrunning = true;
    while(stillrunning){
        system("cls");
        int choice;
        cout<<"Array Stack"<<endl<<endl;
        cout<<"ACTION TOOLS: "<<endl<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display Top"<<endl<<"4. Display Stack"<<endl<<"5. Exit"<<endl<<endl;
        cout<<"Choose [1-5]: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            int input;
            cout<<"Input #: ";
            cin>>input;
            cin.ignore();
            push(input);
            break;
            
            case 2:
            pop();
            break;

            case 3:
            topDisplay();
            break;

            case 4:
            display();
            break;

            case 5:
            stillrunning = false;
            break;

            default:
            cout<<"INVALID INPUT!";
            system("pause");
            break;
        }
    }
}

class Linked{
    private:
    Digit* top = nullptr;
    bool isempty();

    public:
    void pushL(int n);
    void popL();
    void topDisplayL();
    void displayL();
    void uiLinked();
};
bool Linked :: isempty(){
    return top == nullptr;
}
void Linked :: pushL(int n){
    system("cls");
    Digit* newNode = new Digit{n, nullptr};
    newNode->num = n;
    if(top == nullptr){
        top = newNode;
        cout<<"Number Pushed!"<<endl<<endl;
        system("pause");
        return;
    }
    newNode->next = top;
    top = newNode;
    cout<<"Number Pushed!"<<endl<<endl;
    system("pause");
    return;
}
void Linked :: popL(){
    system("cls");
    if(isempty()){
        cout<<"Stack Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    Digit* p = top;
    top = p->next;  
    delete p;
    cout<<"Top Popped!"<<endl<<endl;
    system("pause");
    return;
}
void Linked :: topDisplayL(){
    if(isempty()){
        cout<<"Stack Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    cout<<"Top Display: "<<top->num<<endl<<endl;
    system("pause");
    return;
}
void Linked :: displayL(){
    system("cls");
    if(isempty()){
        cout<<"Stack Empty!"<<endl<<endl;
        system("pause");
        return;
    }
    cout<<"Stack Linked"<<endl<<endl;
    Digit* p = top;
    while(p != nullptr){
        cout<<p->num<<endl;
        p = p->next;
    }
    system("pause");
    return;
}

void Linked :: uiLinked(){
    bool stillrunning = true;
    while(stillrunning){
        system("cls");
        int choice;
        cout<<"Linked List Stack"<<endl<<endl;
        cout<<"ACTION TOOLS: "<<endl<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display Top"<<endl<<"4. Display Stack"<<endl<<"5. Exit"<<endl<<endl;
        cout<<"Choose [1-5]: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            int input;
            cout<<"Enter #: ";
            cin>>input;
            cin.ignore();
            pushL(input);
            break;

            case 2:
            popL();
            break;

            case 3:
            topDisplayL();
            break;

            case 4:
            displayL();
            break;

            case 5:
            stillrunning = false;
            break;

            default:
            cout<<"INVALID INPUT!"<<endl<<endl;
            system("pause");
            break;
        }
    }
}

int main(){
    bool stillRunning = true;
    while(stillRunning){
        system("cls");
        int choice;
        Array ptr;
        Linked pt;
        cout<<"Stack ADT"<<endl<<endl;
        cout<<"Versions: "<<endl<<"1. Array Stack"<<endl<<"2. Linked List Stack"<<endl<<"3. Exit"<<endl<<endl;
        cout<<"Choose Action [1-3]: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            ptr.uiArray();
            break;

            case 2:
            pt.uiLinked();
            break;

            case 3:
            stillRunning = false;
            cout<<"Thank you for using the program!"<<endl<<endl;
            system("pause");
            break;

            default:
            cout<<"INVALID INPUT!"<<endl<<endl;
            system("pause");
            break;
        }
    }
}