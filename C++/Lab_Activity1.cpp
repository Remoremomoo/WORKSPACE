#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <windows.h>
#define MAX 5
using namespace std;

struct Student{
    string name;
    int score;
};

class Records{
private:
    Student s1[MAX];
    int val = -1;
    int locate(string n);
    bool isfull();
    bool isempty();
public:
    void addrecord(string n, int s);
    void delrecord(string n);
    void update(string n);
    void display();
    void retrieve();
    void save();
};

int Records :: locate(string n){
    for(int i = 0; i <= val; i++){
        if(s1[i].name == n){
            return i;
        }
    }
    return -1;
}

bool Records :: isfull(){
    return val == MAX - 1;
}

bool Records :: isempty(){
    return val == -1;
}

void Records :: addrecord(string n, int s){
    system("cls");
    if(isfull()){
        cout<<"RECORD FULL!"<<endl<<endl;
        system("pause");
        return;
    }
    else{
        if(locate(n) == -1){
            int pos = 0;
            while(pos <= val && s1[pos].score >= s){
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

void Records :: delrecord(string n){
    system("cls");
    if(isempty()){
        cout<<"RECORDS EMPTY!"<<endl<<endl;
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

void Records :: update(string n){
    system("cls");
    if(isempty()){
        cout<<"RECORDS EMPTY!"<<endl<<endl;
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
        bool isRunning = true;
        while(isRunning){
            int scoreNew;
            cout<<s1[p].name<<"'s Record: "<<s1[p].score<<endl<<endl;
            cout<<"TOOLS:"<<endl<<"1. Update Score"<<endl<<"2. Exit"<<endl<<endl;
            cout<<endl<<endl<<"Choose: ";
            cin>>choice;
            cin.ignore();

            switch(choice){
            case 1:
                cout<<endl<<"Input New Score: ";
                cin>>scoreNew;
                delrecord(n);
                addrecord(n, scoreNew);

                p = locate(n);

                cout<<endl<<endl<<"Score Updated!"<<endl<<endl;
                system("pause");
                break;
            case 2:
                isRunning = false;
                cout<<"Returning...";
                Sleep(2);
                break;
            default:
                cout<<"INVALID INPUT!"<<endl<<endl;
                system("pause");
                break;
            }
        }
    }
}

void Records :: display(){
    system("cls");
    if(isempty()){
        cout<<"RECORDS EMPTY!"<<endl<<endl;
        system("pause");
        return;
    }
    else{
        cout<<"RECORDS"<<endl<<endl;
        cout<<left<<setw(4)<<"No."<<setw(20)<<"Name"<<setw(6)<<"Score"<<endl;
        for(int i = 0; i <= val; i++){
            cout<<left<<setw(4)<<i + 1<<setw(20)<<s1[i].name<<setw(6)<<s1[i].score<<endl;
        }
        cout<<endl;
        system("pause");
        return;
    }
}

void Records :: save(){
    ofstream outFile("Recordsheet.csv");
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

void Records :: retrieve(){
    ifstream inFile("Recordsheet.csv");
    if(!inFile){
        cout<<"FILE ERROR!"<<endl<<endl;
        system("pause");
        return;
    }
    string line;
    while(getline(inFile, line)){
        stringstream ss(line);
        string name, scoreStr;

        getline(ss, name, ',');
        getline(ss, scoreStr, ',');

        int score = stoi(scoreStr);
        addrecord(name, score);
    }
    inFile.close();
}

int main(){
    Records pointer;
    bool ifReturn = true;

    pointer.retrieve();

    while(ifReturn){
        system("cls");
        string inputName;
        int inputScore, choice;

        cout<<"STUDENT RECORD"<<endl<<endl;
        cout<<"1. Add New Record"<<endl<<"2. Delete Existing Record"<<endl<<"3. Update Existing Record"<<endl<<"4. Display All Records"<<endl<<"5. Exit"<<endl<<endl;
        cout<<"Choose [1-5]: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
        case 1:
            cout<<endl<<endl<<"Enter Name: ";
            getline(cin, inputName);
            cout<<endl<<"Enter Score: ";
            cin>>inputScore;
            cin.ignore();
            pointer.addrecord(inputName, inputScore);
            break;
        case 2:
            cout<<endl<<endl<<"Enter Name: ";
            getline(cin, inputName);
            pointer.delrecord(inputName);
            break;
        case 3:
            cout<<endl<<endl<<"Enter Name: ";
            getline(cin, inputName);
            pointer.update(inputName);
            break;
        case 4:
            pointer.display();
            break;
        case 5:
            pointer.save();
            ifReturn = false;
            cout<<endl<<endl<<"Closing...";
            Sleep(2);
            break;
        default:
            cout<<endl<<endl<<"INVALID INPUT!";
            break;
        }

    }
}
