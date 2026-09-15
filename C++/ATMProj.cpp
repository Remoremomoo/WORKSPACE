#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <stdlib.h>
#define FILENAME "D:\\User_Account.txt"
#define MASTERLIST "Master_List.txt"
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
    Account(string aNum, string aN, string bd, string cN, string pin, float Dep, float initDep){
        this->accNum = aNum;
        this->accName = aN;
        this->birthday = bd;
        this->contactNum = cN;
        this->PIN = pin;
        this->initDeposit = initDep;
        this->balance = Dep;
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
    string getEncNum(){
        return caesar(accNum, 6);
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
    Account* current = nullptr;
    Account* locate(string aN);

    public:
    void saveMaster();
    void retrieveMaster();
    bool userDetectAccount();
    void insertData(Account* newNode);
    void regAcc(string aN, string n, string birth, string contact, string pn, float Dep);
    void writeAccountFile();
    bool retrieveAccountFile();
    float balanceInquiry();
    bool withdraw(float am, string pn);
    bool deposit(float am, string pn);
    bool transfer(string dest, float am, string pn);
    bool pinChange(string pn, string newPIN, string newPIN1);

};

void ATM :: saveMaster(){
    ofstream outFile(MASTERLIST);
    if(!outFile){
        return;
    }
    Account* temp = head;
    while(temp != nullptr){
        outFile<<temp->getEncNum()<<","<<temp->getAccName()<<","<<temp->getBday()<<","<<temp->getContact()<<","<<temp->getEnc()<<","<<temp->getBal()<<","<<temp->getInit()<<endl;
        temp = temp->next;
    }
    outFile.close();
}
void ATM :: retrieveMaster(){
    ifstream inFile(MASTERLIST);
    if(!inFile){
        return;
    }
    string line;
    while(getline(inFile, line)){
        if(line.empty()){
            continue;
        }
        stringstream ss(line);
        string num, name, bday, cont, pin, decrypt, decryptNum, balStr, initDep;
        float bal, initDeposit;
        
        getline(ss, num, ',');
        getline(ss, name, ',');
        getline(ss, bday, ',');
        getline(ss, cont, ',');
        getline(ss, pin, ',');
        getline(ss, balStr, ',');
        getline(ss, initDep, ',');

        bal = stof(balStr);
        initDeposit = stof(initDep);

        decrypt = caesar(pin, 2);
        decryptNum = caesar(num, 4);

        Account* newNode = new Account(decryptNum, name, bday, cont, decrypt, bal, initDeposit);
        insertData(newNode);
    }
}

bool ATM :: userDetectAccount(){
    ifstream inFile(FILENAME);
    if(inFile){
        return true;
    }
    else{
        return false;
    }
}
void ATM :: insertData(Account* newNode){
    if(head == nullptr){
        head = newNode;
        tail = newNode;
        current = newNode;
    }
    else{
        Account* temp = tail;
        tail = newNode;
        current = newNode;
        temp->next = tail;
        tail->prev = temp;
    }
}
void ATM :: regAcc(string aN, string n, string birth, string contact, string pn, float Dep){
    Account* newNode = new Account(aN, n, birth, contact, pn, Dep);
    insertData(newNode);
    writeAccountFile();
    saveMaster();
}
void ATM :: writeAccountFile(){
    ofstream outFile(FILENAME);
    if(!outFile){
        return;
    }

    outFile<<current->getEncNum()<<","<<current->getAccName()<<","<<current->getBday()<<","<<current->getContact()<<","<<current->getEnc()<<","<<current->getBal();

    outFile.close();
}
bool ATM :: retrieveAccountFile(){
    ifstream inFile(FILENAME);
    string line;
    while(getline(inFile, line)){
        stringstream ss(line);
        string num, name, bday, cont, pin, decrypt, decryptNum, balStr;
        float bal;
        
        getline(ss, num, ',');
        getline(ss, name, ',');
        getline(ss, bday, ',');
        getline(ss, cont, ',');
        getline(ss, pin, ',');
        getline(ss, balStr, ',');

        bal = stof(balStr);

        decrypt = caesar(pin, 2);
        decryptNum = caesar(num, 4);

        Account* find = locate(num);
        if(find != nullptr){
            if(find->verifyPIN(decrypt) == true){
                current = find;
                writeAccountFile();
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    return false;
}
Account* ATM :: locate(string aN){
    Account* temp = head;
    while(temp != nullptr){
        if(temp->getAccNum() == aN){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
float ATM :: balanceInquiry(){
    Account* cur = current;
    return cur->getBal();
}
bool ATM :: withdraw(float am, string pn){
    if(am >= 100 && current->getBal() >= am && (int)am % 100 == 0){
        if(current->verifyPIN(pn) == true){
            float curBal = current->getBal() - am;
            current->setBal(curBal);
            writeAccountFile();
            saveMaster();
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool ATM :: deposit(float am, string pn){
    if(am > 0){
        if(current->verifyPIN(pn) == true){
            float bal = current->getBal() + am;
            current->setBal(bal);
            writeAccountFile();
            saveMaster();
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool ATM :: transfer(string destNum, float am, string pn){
    Account* dest = locate(destNum);
    if(dest != nullptr){
        if(am >= 100 && current->getBal() >= am && (int)am % 100 == 0){
            if(current->verifyPIN(pn) == true){
                float bal = current->getBal() - am;
                current->setBal(bal);
                float destBal = dest->getBal() + am;
                dest->setBal(destBal);
                writeAccountFile();
                saveMaster();
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool ATM :: pinChange(string pn, string newPIN, string newPIN1){
    if(current->verifyPIN(pn) == true){
        if(newPIN == newPIN1){
            current->setPIN(newPIN);
            writeAccountFile();
            saveMaster();
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}