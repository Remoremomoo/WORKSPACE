#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <chrono>
#include <thread>
#include <limits>
#define FILENAME "MP3_Recordsheet.csv"
using namespace std;

struct Student{
    string name;
    int score;
    Student* next;
    Student* prev;
};

class Recordsheet3 {
    private:
    bool isempty();
    Student* head = nullptr;
    Student* locate(string n);
    void typewriter(string text, int delay = 20);

    public:
    void addrecord(string n, int s);
    void deleterecord(string n);
    void updaterecord(string n);
    void display();
    void save();
    void retrieve();
    void welcome();
};

bool Recordsheet3 :: isempty(){
    return head == nullptr;
}

Student* Recordsheet3 :: locate(string n){
    Student* t = head;
    while(t != nullptr){
        if(t->name == n){
            return t;
        }
        t = t->next;
    }
    return nullptr;
}

void Recordsheet3 :: addrecord(string n, int s){
    system("cls");
    if(locate(n) == nullptr){
        Student* newNode = new Student{n, s, nullptr, nullptr};
        if(head == nullptr){
            head = newNode;
            return;
        }
        Student* tail = head;
        if(tail->name >= n){
            head = newNode;
            newNode->next = tail;
            tail->prev = newNode;
            return;
        }
        Student* tempor = head;
        while(tempor->next != nullptr && tempor->next->name < n){
            tempor = tempor->next;
        }
        newNode->next = tempor->next;
        newNode->prev = tempor;
        if(newNode->next != nullptr){
            newNode->next->prev = newNode;
        }
        tempor->next = newNode;
    }
    else{
        cout<<"NAME ALREADY EXIST!"<<endl<<endl;
        system("pause");
        return;
    }
}

void Recordsheet3 :: deleterecord(string n){
    system("cls");
    if(isempty()){
        cout<<"RECORDSHEET EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    else{
        if(locate(n) == nullptr){
            cout<<"NAME DOES NOT EXIST!"<<endl<<endl;
            system("pause");
            return;
        }
        else{
            if(head->name == n){
                if(head->next != nullptr){
                    Student* delNode = head;
                    head = head->next;
                    head->prev = nullptr;
                    delete delNode;
                    return;
                }
                delete head;
                head = nullptr;
                return;
            }
            else{
                Student* delNode = locate(n);
                delNode->prev->next = delNode->next;
                if(delNode->next != nullptr){
                    delNode->next->prev = delNode->prev;
                }
                delete delNode;
                return;
            }
        }
    }
}

void Recordsheet3 :: updaterecord(string n){
    system("cls");
    if(isempty()){
        cout<<"RECORDSHEET EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    Student* loc = locate(n);
    if(loc == nullptr){
        cout<<"NAME DOES NOT EXIST!"<<endl<<endl;
        system("pause");
        return;
    }
    int choice;
    bool isRunning = true;
    while(isRunning){
        int newScore;
        cout<<loc->name<<"'s Record"<<endl;
        cout<<"Score: "<<loc->score<<endl<<endl;

        cout<<"ACTION TOOLS"<<endl;
        cout<<"1. Update Score"<<endl<<"2. Exit"<<endl<<endl;
        cout<<"Choose [1-2]: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:

            cout<<endl<<endl<<"Enter New Score: ";
            cin>>newScore;
            cin.ignore();
            loc->score = newScore;

            system("cls");
            cout<<"SCORE UPDATED!"<<endl<<endl;
            system("pause");
            break;
            
            case 2:
            isRunning = false;
            cout<<endl<<endl<<"Returning...";
            Sleep(200);
            break;
            
            default:
            cout<<endl<<endl<<"INVALID TOOL!"<<endl<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            break;
        }
    }
}

void Recordsheet3 :: display(){
    system("cls");
    if(isempty()){
        cout<<"RECORDSHEET EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    Student* tempor = head;
    int i = 1;
    cout<<"RECORDSHEET"<<endl<<endl;
    cout<<left<<setw(4)<<"No."<<setw(20)<<"Name"<<setw(6)<<"Score"<<endl;
    while(tempor != nullptr){
        cout<<left<<setw(4)<<i<<setw(20)<<tempor->name<<setw(6)<<tempor->score<<endl;
        tempor = tempor->next;
        i++;
    }
    cout<<endl;
    system("pause");
    return;
}

void Recordsheet3 :: save(){
    ofstream outFile(FILENAME);
    if(!outFile){
        cout<<"FILE ERROR!"<<endl<<endl;
        system("pause");
        return;
    }
    Student* tempor = head;
    while(tempor != nullptr){
        outFile<<tempor->name<<","<<tempor->score<<endl;
        tempor = tempor->next;
    }
    outFile.close();
}

void Recordsheet3 :: retrieve(){
    ifstream inFile(FILENAME);
    if(!inFile){
        cout<<"FILE ERROR!"<<endl<<endl;
        system("pause");
        return;
    }
    string line;
    while(getline(inFile, line)){
        if(line.empty()){
            continue;
        }
        stringstream ss(line);
        string name, strScore;

        getline(ss, name, ',');
        getline(ss, strScore, ',');


        int score = stoi(strScore);
        addrecord(name, score);
    }
    inFile.close();
}

void Recordsheet3 :: welcome(){
    system("cls");
    typewriter("=====================================");
    cout<<endl;
    Beep(800, 200);
    typewriter("      WELCOME");
    Beep(800, 200);
    typewriter(" TO");
    Beep(800, 200);
    typewriter(" RECORDSHEET");
    Beep(800, 200);
    typewriter(" 3");
    cout<<endl;
    typewriter("=====================================");
    cout<<endl<<endl;
    system("pause");
}

void Recordsheet3 :: typewriter(string text, int delay){
    for(char c : text){
        cout<< c;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

int main(){
    Recordsheet3 ptr;
    string inputName;
    int inputScore, inputChoice;
    bool stillRunning = true;

    ptr.retrieve();
    ptr.welcome();

    while(stillRunning){
        system("cls");
        cout<<"RECORDSHEET 3"<<endl<<endl;
        cout<<"1. ADD RECORD"<<endl<<"2. DELETE RECORD"<<endl<<"3. UPDATE RECORD"<<endl<<"4. DISPLAY ALL RECORDS"<<endl<<"5. EXIT"<<endl<<endl;
        cout<<"Choose: ";
        cin>>inputChoice;
        cin.ignore();

        switch(inputChoice){
            case 1:
            cout<<endl<<endl<<"Enter name: ";
            getline(cin, inputName);
            cout<<"Enter score: ";
            cin>>inputScore;
            cin.ignore();
            ptr.addrecord(inputName, inputScore);
            break;
            
            case 2:
            cout<<endl<<endl<<"Enter name: ";
            getline(cin, inputName);
            ptr.deleterecord(inputName);
            break;

            case 3:
            cout<<endl<<endl<<"Enter name: ";
            getline(cin, inputName);
            ptr.updaterecord(inputName);
            break;

            case 4:
            ptr.display();
            break;

            case 5:
            ptr.save();
            stillRunning = false;
            cout<<endl<<endl<<"CLOSING....";
            Sleep(200);
            Beep(800, 200);
            break;

            default:
            cout<<endl<<endl<<"INVALID ACTION TOOL!"<<endl<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            break;
        }
    }
}