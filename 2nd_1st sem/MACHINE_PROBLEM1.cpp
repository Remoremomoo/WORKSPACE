#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <windows.h>
#include <chrono>
#include <thread>
#define MAX 5
#define FILENAME "MP1_Recordsheet.csv"
using namespace std;

struct Student{
    string name;
    int score;
};

class Recordsheet{
    private:
    Student s1[MAX];
    int val = -1;
    bool isfull();
    bool isempty();
    int locate(string n);
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

void Recordsheet :: typewriter(string text, int delay){
    for(char c : text){
        cout<< c;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

bool Recordsheet :: isfull(){
    return val == MAX - 1;
}

bool Recordsheet :: isempty(){
    return val == -1;
}

int Recordsheet :: locate(string n){
    for(int i = 0; i <= val; i++){
        if(s1[i].name == n){
            return i;
        }
    }
    return -1;
}

void Recordsheet :: addrecord(string n, int s){
    system("cls");
    if(isfull()){
        cout<<"RECORDSHEET FULL!"<<endl<<endl;
        system("pause");
        return;
    }
    else{
        if(locate(n) == -1){
            int pos = 0;
            while(pos <= val && s1[pos].name < n){
                pos++;
            }
            for(int i = val; i >= pos; i--){
                s1[i + 1] = s1[i];
            }
            s1[pos].name = n;
            s1[pos].score = s;
            val++;
        }
        else{
            cout<<"NAME ALREADY EXIST!"<<endl<<endl;
            system("pause");
            return;
        }
    }
}

void Recordsheet :: deleterecord(string n){
    system("cls");
    if(isempty()){
        cout<<"RECORDSHEET IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    else{
        int p = locate(n);
        if(p == -1){
            cout<<"NAME DOES NOT EXIST!"<<endl<<endl;
            system("pause");
            return;
        }
        else{
            for(int i = p; i <= val; i++){
                s1[i] = s1[i + 1];
            }
            val--;
        }
    }
}

void Recordsheet :: updaterecord(string n){
    system("cls");
    if(isempty()){
        cout<<"RECORDSHEET IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    else{
        int p = locate(n), choice;
        if(p == -1){
            cout<<"NAME DOES NOT EXIST!"<<endl<<endl;
            system("pause");
            return;
        }
        bool Running = true;
        while(Running){
            int newScore;
            cout<<s1[p].name<<"'s RECORD"<<endl;
            cout<<"Score: "<<s1[p].score<<endl<<endl;
            cout<<"Available Actions: "<<endl;
            cout<<"1. Update Score"<<endl<<"2. Exit"<<endl<<endl;
            cout<<"Choose Action: ";
            cin>>choice;
            cin.ignore();
            switch(choice){
                case 1:
                cout<<endl<<"Enter New Score: ";
                cin>>newScore;
                cin.ignore();
                deleterecord(n);
                addrecord(n, newScore);

                p = locate(n);

                cout<<endl<<endl<<"SCORE IS UPDATED!";
                system("pause");
                break;
                
                case 2:
                Running = false;
                cout<<"Returning";
                Sleep(1);
                cout<<".";
                Sleep(1);
                cout<<".";
                break;
                default:
                cout<<endl<<endl<<"INVALID ACTION!"<<endl<<endl;
                system("pause");
                break;
            }
        }
    }
}

void Recordsheet :: display(){
    system("cls");
    if(isempty()){
        cout<<"RECORDSHEET IS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    cout<<"RECORDSHEET"<<endl<<endl;
    cout<<left<<setw(4)<<"No."<<setw(20)<<"Name"<<setw(6)<<"Score"<<endl;
    for(int i = 0; i <= val; i++){
        cout<<left<<setw(4)<<i + 1<<setw(20)<<s1[i].name<<setw(6)<<s1[i].score<<endl;
    }
    system("pause");
}

void Recordsheet :: savedata(){
    ofstream outFile(FILENAME);
    if(!outFile){
        cout<<"FILE ERROR!"<<endl<<endl;
        system("pause");
        return;
    }
    for(int i = 0; i <= val; i++){
        outFile<<s1[i].name<<","<<s1[i].score<<endl;
    }
    outFile.close();
}

void Recordsheet :: retrievedata(){
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

void Recordsheet :: welcome(){
    system("cls");
    typewriter("=====================================");
    cout<<endl;
    Beep(800, 200);
    typewriter("         WELCOME");
    Beep(800, 200);
    typewriter(" TO");
    Beep(800, 200);
    typewriter(" RECORDSHEET");
    Beep(800, 200);
    typewriter(" 1");
    cout<<endl;
    typewriter("=====================================");
    cout<<endl<<endl;
    system("pause");
}

int main(){
    Recordsheet p;
    string inpName;
    int inpScore, inpChoice;
    bool stillRunning = true;

    p.retrievedata();
    p.welcome();

    while(stillRunning){
        system("cls");
        cout<<"RECORDSHEET 1"<<endl<<endl;
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
            p.addrecord(inpName, inpScore);
            break;
            
            case 2:
            cout<<endl<<endl<<"Enter name: ";
            getline(cin, inpName);
            p.deleterecord(inpName);
            break;

            case 3:
            cout<<endl<<endl<<"Enter name: ";
            getline(cin, inpName);
            p.updaterecord(inpName);
            break;

            case 4:
            p.display();
            break;

            case 5:
            p.savedata();
            stillRunning = false;
            cout<<endl<<endl<<"CLOSING....";
            Sleep(2);
            Beep(800, 200);
            break;

            default:
            cout<<endl<<endl<<"INVALID ACTION TOOL!"<<endl<<endl;
            system("pause");
            break;
        }
    }
}