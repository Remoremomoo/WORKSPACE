#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <stdlib.h>
#define FILENAME "D:\\User_Account.txt"
using namespace std;

string caesar(string code, int numShift){
        for(int i = 0; i < code.length(); i++){
            int digit = code[i] - '0';
            digit = (digit + numShift) % 10;
            code[i] = digit + '0';
        }
        return code;
    }

struct Account{
    private:
    string accNum, accName, birthday, contactNum, PIN;
    float initDeposit, balance;

    public:
    Account* next;
    Account* prev;
    Account(string aNum, string aN, string bd, string cN, string pin, float iDep){
        this->accNum = aNum;
        this->accName = aN;
        this->birthday = bd;
        this->contactNum = cN;
        this->PIN = pin;
        this->initDeposit = iDep;
        this->balance = this->initDeposit;
        this->next = nullptr;
        this->prev = nullptr;
    }
    string getAccNum(){
        return accNum;
    }
    string getAccName(){
        return accName;
    }
    string getBday(){
        return birthday;
    }
    string getContact(){
        return contactNum;
    }
    string getEnc(){
        return caesar(PIN, 8);
    }
    float getInit(){
        return initDeposit;
    }
    float getBal(){
        return balance;
    }
    void setPIN(string changePIN){
        PIN = changePIN;
    }
    void setBal(float addBalance){
        balance = addBalance;
    }
    bool verifyPIN(string auth){
        if(PIN == auth){
            return true;
        }
        else{
            return false;
        }
    }
};

class ATM{
    private:
    Account* head = nullptr;
    Account* tail = nullptr;

    public:
    bool userDetectAccount();
    void regAcc(string aN, string n, string birth, string contact, string pn, float Dep);
    void writeAccountFile();
    void retrieveAccountFile();


};

bool ATM :: userDetectAccount(){
    ifstream inFile(FILENAME);
    if(inFile){
        return true;
    }
    else{
        return false;
    }
}
void ATM :: regAcc(string aN, string n, string birth, string contact, string pn, float Dep){
    Account* newNode = new Account(aN, n, birth, contact, pn, Dep);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        Account* temp = tail;
        tail = newNode;
        temp->next = tail;
        tail->prev = temp;
    }
    writeAccountFile();
}
void ATM :: writeAccountFile(){
    ofstream outFile(FILENAME);
    if(!outFile){
        return;
    }

    outFile<<tail->getAccNum()<<","<<tail->getAccName()<<","<<tail->getBday()<<","<<tail->getContact()<<","<<tail->getEnc()<<","<<tail->getBal();

    outFile.close();
}
void ATM :: retrieveAccountFile(){
    ifstream inFile(FILENAME);
    string line;
    while(getline(inFile, line)){
        stringstream ss(line);
        string num, name, bday, cont, pin;
        
    }
}