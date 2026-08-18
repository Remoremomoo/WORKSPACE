#include <iostream>
#include <stdlib.h>
#include <iomanip>
#define MAX 5
using namespace std;

struct Student{
    string name;
    int q1, q2, q3;
};

class ClassRecord{
private:
    Student s1[MAX];
    int val = -1;
    bool isfull();
    bool isempty();
public:
    int locate(string n);
    void ui();
    void addRec(string n, int x1, int x2, int x3);
    void delRec(string n);
    void update(string n);
    void display();
    void save();
    void retrieve();
    int menu();
};

bool ClassRecord :: isfull(){
    return val == MAX - 1;
}

bool ClassRecord :: isempty(){
    return val == -1;
}

int ClassRecord :: locate(string n){
    for(int i = 0; i <= val; i++){
        if(s1[i].name == n){
            return i;
        }
    }
    return -1;
}

void ClassRecord :: addRec(string n, int x1, int x2, int x3){
    system("cls");

    if(isfull()){
        cout<<"RECORD ALREADY FULL!"<<endl<<endl;
        system("pause");
    }
    else{
        val++;
        s1[val].name = n;
        s1[val].q1 = x1;
        s1[val].q2 = x2;
        s1[val].q3 = x3;
    }
}

void ClassRecord :: delRec(string n){
    int p, i;

    p = locate(n);

    if(p == -1){
        cout<<"NAME DOES NOT EXIST!"<<endl<<endl;
        system("pause");
    }
    else{
        for(i = p; i <= val; i++){
            s1[i].q1 = s1[i + 1].q1;
            s1[i].q2 = s1[i + 1].q2;
            s1[i].q3 = s1[i + 1].q3;
            s1[i].name = s1[i + 1].name;
        }
        val--;
    }
}

void ClassRecord :: update(string n){
    int p, i;
    float ave;

    if(isempty()){
        cout<<"EMPTY RECORD SHEET!"<<endl<<endl;
        system("pause");
    }
    else{
        int score;
        p = locate(n);

        if(p == -1){
            cout<<"NAME DOES NOT EXIST!"<<endl<<endl;
            system("pause");
        }
        else{
            while(true){
                int choice = 0;
                ave = (float)(s1[p].q1 + s1[p].q2 + s1[p].q3)/3;
                system("cls");
                cout<<"RECORD OF "<<n;
                cout<<endl<<left<<setw(20)<<"NAME"<<setw(6)<<"QUIZ1"<<setw(6)<<"QUIZ2"<<setw(6)<<"QUIZ3"<<setw(8)<<"AVERAGE";
                cout<<endl<<left<<setw(20)<<s1[p].name<<setw(6)<<s1[p].q1<<setw(6)<<s1[p].q2<<setw(6)<<s1[p].q3<<setw(8)<<setprecision(2)<<ave;
                cout<<endl<<endl<<"CHOOSE QUIZ TO UPDATE:"<<endl<<"1. QUIZ 1"<<endl<<"2. QUIZ 2"<<endl<<"3. QUIZ 3"<<endl<<"4. RETURN TO MENU";
                cout<<endl<<endl<<"CHOOSE [1-4]: ";
                cin>>choice;

                switch(choice){
                case 1:{
                    cout<<"ENTER NEW SCORE: ";
                    cin>>score;
                    s1[p].q1 = score;
                    string newName = s1[p].name;
                    int score1 = s1[p].q1;
                    int score2 = s1[p].q2;
                    int score3 = s1[p].q3;

                    delRec(newName);
                    addRec(newName, score1, score2, score3);
                    break;
                }
                case 2:{
                    cout<<"ENTER NEW SCORE: ";
                    cin>>score;
                    s1[p].q2 = score;
                    string newName = s1[p].name;
                    int score1 = s1[p].q1;
                    int score2 = s1[p].q2;
                    int score3 = s1[p].q3;

                    delRec(newName);
                    addRec(newName, score1, score2, score3);
                    break;
                }
                case 3:{
                    cout<<"ENTER NEW SCORE: ";
                    cin>>score;
                    s1[p].q3 = score;
                    string newName = s1[p].name;
                    int score1 = s1[p].q1;
                    int score2 = s1[p].q2;
                    int score3 = s1[p].q3;

                    delRec(newName);
                    addRec(newName, score1, score2, score3);
                    break;
                }
                case 4:{
                    return;
                    break;
                }
                default:{
                    cout<<endl<<endl<<"INVALID CHOICE!"<<endl<<endl;
                    system("pause");
                    break;
                }
                }
            }
        }
    }
}

void ClassRecord :: display(){
    int i;
    float ave;
    system("cls");

    if(isempty()){
        cout<<"EMPTY RECORD LIST!"<<endl<<endl;
        system("pause");
    }
    else{
        cout<<"RECORDS"<<endl;
        cout<<left<<setw(4)<<"NO. "<<setw(20)<<"NAME"<<setw(6)<<"QUIZ1"<<setw(6)<<"QUIZ2"<<setw(6)<<"QUIZ3"<<setw(8)<<"AVERAGE";

        for(i = 0; i <= val; i++){
            ave = (float)(s1[i].q1 + s1[i].q2 + s1[i].q3)/3;
            cout<<endl<<left<<setw(4)<<i + 1<<setw(20)<<s1[i].name<<setw(6)<<s1[i].q1<<setw(6)<<s1[i].q2<<setw(6)<<s1[i].q3<<setw(8)<<setprecision(2)<<ave;
        }
        system("pause");
    }
}

void ClassRecord :: save(){
    FILE *fp;
    int i;

    fp = fopen("MP12.txt", "w");

    if(fp == NULL){
        cout<<"FILE ERROR!"<<endl<<endl;
        system("pause");
    }
    else{
        for(i = 0; i <= val; i++){
            fprintf(fp, " %s,%d,%d,%d\n", s1[i].name.c_str(), s1[i].q1, s1[i].q2, s1[i].q3);
        }
        fclose(fp);
    }
}

void ClassRecord :: retrieve(){
    FILE *fp;
    char line[100], name[50];
    int qui1, qui2, qui3;

    fp = fopen("MP12.txt", "r");

    if(fp == NULL){
        cout<<"FILE ERROR!"<<endl<<endl;
        system("pause");
    }
    else{
        while(fgets(line, sizeof(line), fp)){
            sscanf(line, "%[^,],%d,%d,%d", name, &qui1, &qui2, &qui3);
            addRec(name, qui1, qui2, qui3);
        }
        fclose(fp);
    }
}

int ClassRecord :: menu(){
    int choice = 0;

    system("cls");
    cout<<"MENU"<<endl;
    cout<<"1. ADD RECORD"<<endl<<"2. DELETE RECORD"<<endl<<"3. UPDATE RECORD"<<endl<<"4. DISPLAY RECORD"<<endl<<"5. EXIT"<<endl<<endl;
    cout<<"CHOOSE [1-4]: ";
    cin>>choice;
    return choice;
}

int main(){
    ClassRecord record;
    string nm;
    int qz1, qz2, qz3;

    record.retrieve();

    while(true){
        switch(record.menu()){
        case 1:
            cout<<endl<<endl<<"ENTER NAME: ";
            getchar();
            cin>>nm;
            if(record.locate(nm) > -1){
                cout<<"NAME ALREADY EXISTS!"<<endl<<endl;
                system("pause");
            }
            else{
                cout<<"ENTER QUIZ 1: ";
                cin>>qz1;
                cout<<"ENTER QUIZ 2: ";
                cin>>qz2;
                cout<<"ENTER QUIZ 3: ";
                cin>>qz3;

                record.addRec(nm, qz1, qz2, qz3);
                cout<<nm<<" SUCCESSFULLY RECORDED!"<<endl<<endl;
                system("pause");
            }
            break;
        case 2:
            cout<<endl<<endl<<"ENTER NAME: ";
            getchar();
            cin>>nm;
            record.delRec(nm);
            break;
        case 3:
            cout<<endl<<endl<<"ENTER NAME: ";
            getchar();
            cin>>nm;
            record.update(nm);
            break;
        case 4:
            record.display();
            break;
        case 5:
            record.save();
            exit(false);
            break;
        default:
            cout<<endl<<endl<<"INVALID INPUT!"<<endl<<endl;
            system("pause");
            break;
        }
    }

}
