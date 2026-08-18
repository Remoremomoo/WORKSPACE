#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
#include <chrono>
#include <thread>
#include <limits>
#define FILENAME "MP2_Recordsheet.csv"
using namespace std;

struct Student{
    string name;
    int score;
    Student* next;
};

class Recordsheet2{
    private:
    Student* head = nullptr;
    bool isempty();
    Student* locate(string n);
    void typewriter(string text, int delay = 20);

    public:
    void addrecord(string n, int s);
    void deleterecord(string n);
    void updaterecord(string n);
    void display();
    void savedata();
    void retrievedata();
    void welcome();
};

bool Recordsheet2 :: isempty(){
    return head == nullptr;
}

Student* Recordsheet2 :: locate(string n){
    Student* temp = head;
    while(temp != nullptr){
        if(temp->name == n){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void Recordsheet2 :: addrecord(string n, int s){
    system("cls");
    if(locate(n) != nullptr){
        cout<<"NAME ALREADY EXIST!"<<endl<<endl;
        system("pause");
        return;
    }
    Student* newNode = new Student{n, s, nullptr};
    if(head == nullptr || head->name > n){
        newNode->next = head;
        head = newNode;
        return;
    }
    Student* temp = head;
    while(temp->next != nullptr && temp->next->name < n){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;   
}

void Recordsheet2 :: deleterecord(string n){
    system("cls");
    if(isempty()){
        cout<<"RECORDSHEET IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    if(locate(n) == nullptr){
        cout<<"NAME DOES NOT EXIST!"<<endl<<endl;
        system("pause");
        return;
    }
    else{
        if(head->name == n){
            Student* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Student* prev = head;
        Student* temp = head->next;
        while(temp->name != n){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
}

void Recordsheet2 :: updaterecord(string n){
    system("cls");
    if(isempty()){
        cout<<"RECORDSHEET IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    Student* loc = locate(n);
    if(loc == nullptr){
        cout<<"NAME DOES NOT EXIST!"<<endl<<endl;
        system("pause");
        return;
    }
    else{
        int choice;
        bool Running = true;
        while(Running){
            int newScore;
            cout<<loc->name<<"'s RECORD"<<endl;
            cout<<"Score: "<<loc->score<<endl<<endl;
            cout<<"ACTION TOOLS:"<<endl;
            cout<<"1. Update Score"<<endl<<"2. Exit"<<endl<<endl;
            cout<<"Choose Action [1-2]: ";
            cin>>choice;
            cin.ignore();

            switch(choice){
                case 1:
                cout<<endl<<endl<<"Enter New Score: ";
                cin>>newScore;
                cin.ignore();
                deleterecord(n);
                addrecord(n, newScore);

                loc = locate(n);
                cout<<endl<<endl<<"SCORE IS UPDATED!"<<endl;
                system("pause");
                break;

                case 2:
                Running = false;
                cout<<endl<<endl<<"Returning";
                Sleep(200);
                cout<<".";
                Sleep(200);
                cout<<".";
                break;
                
                default:
                cout<<endl<<endl<<"INVALID ACTION!"<<endl<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("pause");
                break;
            }
        }
    }
}

void Recordsheet2 :: display(){
    system("cls");
    if(isempty()){
        cout<<"RECORDSHEET IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    cout<<"RECORDSHEET"<<endl<<endl;
    cout<<left<<setw(4)<<"No."<<setw(20)<<"Name"<<setw(6)<<"Score"<<endl;
    int i = 1;
    Student* temp = head;
    while(temp != nullptr){
        cout<<left<<setw(4)<<i<<setw(20)<<temp->name<<setw(6)<<temp->score<<endl;
        temp = temp->next;
        i++;
    }
    system("pause");
    return;
}

void Recordsheet2 :: savedata(){
    ofstream outFile(FILENAME);
    if(!outFile){
        cout<<"FILE ERROR"<<endl<<endl;
        system("pause");
        return;
    }
    Student* temp = head;
    while(temp != nullptr){
        outFile<<temp->name<<","<<temp->score<<endl;
        temp = temp->next;
    }
    outFile.close();
}

void Recordsheet2 :: retrievedata(){
    ifstream inFile(FILENAME);
    if(!inFile){
        cout<<"FILE ERROR!"<<endl<<endl;
        system("pause");
        return;
    }
    string line;
    while(getline(inFile, line)){
        stringstream ss(line);
        string name, strScore;

        getline(ss, name, ',');
        getline(ss, strScore, ',');

        int score = stoi(strScore);
        addrecord(name, score);
    }
    inFile.close();
}

void Recordsheet2 :: welcome(){
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
    typewriter(" 2");
    cout<<endl;
    typewriter("=====================================");
    cout<<endl<<endl;
    system("pause");
}

void Recordsheet2 :: typewriter(string text, int delay){
    for(char c : text){
        cout<< c;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

int main(){
    Recordsheet2 ptr;
    string inpName;
    int inpScore, inpChoice;
    bool stillRunning = true;

    ptr.retrievedata();
    ptr.welcome();

    while(stillRunning){
        system("cls");
        cout<<"RECORDSHEET 2"<<endl<<endl;
        cout<<"ACTION TOOLS:"<<endl<<"1. ADD A RECORD"<<endl<<"2. DELETE A RECORD"<<endl<<"3. UPDATE A RECORD"<<endl<<"4. DISPLAY ALL RECORDS"<<endl<<"5. EXIT"<<endl<<endl;
        cout<<"CHOOSE YOUR TOOL [1-5]: ";
        cin>>inpChoice;
        cin.ignore();

        switch(inpChoice){
            case 1:
            cout<<endl<<endl<<"Enter name: ";
            getline(cin, inpName);
            cout<<"Enter score: ";
            cin>>inpScore;
            cin.ignore();
            ptr.addrecord(inpName, inpScore);
            break;
            
            case 2:
            cout<<endl<<endl<<"Enter name: ";
            getline(cin, inpName);
            ptr.deleterecord(inpName);
            break;

            case 3:
            cout<<endl<<endl<<"Enter name: ";
            getline(cin, inpName);
            ptr.updaterecord(inpName);
            break;

            case 4:
            ptr.display();
            break;

            case 5:
            ptr.savedata();
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