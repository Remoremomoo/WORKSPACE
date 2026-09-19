#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define MASTERLIST "Master_List.txt"
using namespace std;

string Drive(){
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(size_t i = 0; i < letters.length(); i++){
        if(letters[i] == 'C'){
            continue;
        }
        string pathDrive = string(1, letters[i]) + ":\\";
        UINT type = GetDriveTypeA(pathDrive.c_str());

        if(type == DRIVE_REMOVABLE || type == DRIVE_FIXED || type == DRIVE_REMOTE){
            return string(1, letters[i]);
        }
    }
    return "";
}
string getFilePath(){
    return Drive() + ":\\User_Account.txt";
}

string caesar(string code, int numShift){
        for(int i = 0; i < code.length(); i++){
            int digit = code[i] - '0';
            digit = (digit + numShift) % 10;
            code[i] = digit + '0';
        }
        return code;
    }

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

string getMaskedPIN() {
    string pin = "";
    
    const char ENTER_KEY     = 13;
    const char BACKSPACE_KEY = 8;
    
    while (true) {
        char ch = _getch(); 

        if (ch == ENTER_KEY) {
            if (pin.length() >= 4 && pin.length() <= 6) {
                break; 
            }
        } else if (ch == BACKSPACE_KEY) {
        	if (!pin.empty()) {
                pin.pop_back();
                cout << "\b \b"; 
            }
        } else if (isdigit(ch) && pin.length() < 6) {
            pin.push_back(ch);
            cout << "*"; 
        }
    }
    
    return pin;
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
    void insertCardUI();
    void saveMaster();
    void retrieveMaster();
    bool userDetectAccount();
    bool pinChecker(string pinCheck);
    void insertData(Account* newNode);
    bool regAcc(string aN, string n, string birth, string contact, string pn, float Dep);
    void writeAccountFile();
    bool retrieveAccountFile();
    float balanceInquiry();
    bool withdraw(float am, string pn);
    bool deposit(float am, string pn);
    bool transfer(string dest, float am, string pn);
    bool pinChange(string pn, string newPIN, string newPIN1);
    void checkingFileUI();
    bool authenticate(string pn);
    bool verifyTransactionPIN(int lineY, string &outPIN);
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

bool ATM :: pinChecker(string pinCheck){
    if(pinCheck.length() < 4 || pinCheck.length() > 6){
        return false;
    }
    for(int i = 0; i < pinCheck.length(); i++){
        int digit = pinCheck[i] - '0';
        if(digit < 0 || digit > 9){
            return false;
        }
        else{
            continue;
        }
    }
    return true;

}

bool ATM :: userDetectAccount(){
    ifstream inFile(getFilePath());
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
bool ATM :: regAcc(string aN, string n, string birth, string contact, string pn, float Dep){
    if(pinChecker(pn) == true){
        if(Dep >= 5000){
            Account* newNode = new Account(aN, n, birth, contact, pn, Dep);
            insertData(newNode);
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
void ATM :: writeAccountFile(){
    ofstream outFile(getFilePath());
    if(!outFile){
        return;
    }

    outFile<<current->getEncNum()<<","<<current->getAccName()<<","<<current->getBday()<<","<<current->getContact()<<","<<current->getEnc()<<","<<current->getBal();

    outFile.close();
}
bool ATM :: retrieveAccountFile(){
    ifstream inFile(getFilePath());
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

        Account* find = locate(decryptNum);
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
bool ATM :: deposit(float am, string pn){
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
bool ATM :: transfer(string destNum, float am, string pn){
    Account* dest = locate(destNum);
    if(dest != nullptr){
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
bool ATM :: pinChange(string pn, string newPIN, string newPIN1){
    if(current->verifyPIN(pn) == true){
        if(pinChecker(newPIN) == true){
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
    else{
        return false;
    }
}
bool ATM :: authenticate(string pn){
    if(current == nullptr){
        return false;
    }
    return current->verifyPIN(pn);
}
void ATM :: checkingFileUI() {
	system("cls");
	gotoxy(10, 5); cout << "Reading Card Details...";
    gotoxy(10, 7); cout << "[ ";
    for (int i = 0; i < 20; i++) {
        cout << "=";
        Sleep(40);
    }
    cout << " ]";
    Sleep(200);
}
void ATM :: insertCardUI() {
    system("cls");
    Sleep(1000);
	gotoxy(26, 10); cout << ".--------------------------.";
    gotoxy(26, 11); cout << "|                          |";
    gotoxy(26, 12); cout << "|    PLEASE INSERT CARD    |";
    gotoxy(26, 13); cout << "|                          |";
    gotoxy(26, 14); cout << "'--------------------------'";
}
void receipt(string type, string l1, string l2, string foot) {
    system("cls");
    gotoxy(10, 3);  cout << "========================================";
    gotoxy(10, 4);  cout << "            TRANSACTION RECEIPT         ";
    gotoxy(10, 5);  cout << "========================================";
    gotoxy(10, 7);  cout << " Transaction Type : " << type;
    if (!l1.empty()) { gotoxy(10, 8); cout << " " << l1; }
    if (!l2.empty()) { gotoxy(10, 9); cout << " " << l2; }
    gotoxy(10, 10); cout << " Status            : SUCCESS";
    gotoxy(10, 12); cout << "========================================";
    gotoxy(10, 14); cout << foot;

    _getch();
}
bool ATM::verifyTransactionPIN(int lineY, string &outPIN) {
    int attempts = 0;
    while (attempts < 3) {
        gotoxy(10, lineY); cout << "Confirm PIN:                               ";
        gotoxy(23, lineY); 
        outPIN = getMaskedPIN();

        if (authenticate(outPIN)) {
            return true;
        } else {
            attempts++;
            if (attempts < 3) {
                gotoxy(10, lineY + 2); cout << "INVALID PIN! Attempts remaining: " << (3 - attempts);
                Sleep(1000);
                gotoxy(10, lineY + 2); cout << "                                           ";
            }
        }
    }
    return false;
}

int main() {
	ATM atmSystem;
	atmSystem.retrieveMaster(); 
	
	while(true) {
		while (Drive() == "") {
			atmSystem.insertCardUI();
            Sleep(500);
		}
		
		atmSystem.checkingFileUI(); 
		bool cardExists = atmSystem.userDetectAccount();
		
		if (!cardExists) {
			string accNum, name, bday, contact, pin;
			float initDep;
			bool regSuccess = false;
			
			system("cls");
			gotoxy(10, 3); cout << "******** ! ACCOUNT REGISTRATION MENU ! ********";
            gotoxy(10, 4); cout << "Card file not found. Please register below.\n";

            do{
                gotoxy(10, 6); cout << "Enter 5-Digit Acc No : "; cin >> accNum;
                cin.ignore();
                if(accNum.length() != 5){
                    gotoxy(10, 8); cout << "Error: Account Number must be 5-digit! Please try again.";
	                Sleep(1000);
	                gotoxy(10, 8); cout << "                                             ";
	                gotoxy(37, 7); cout << "            ";
                }
            }while(accNum.length() != 5);
            gotoxy(10, 7); cout << "Full Name            : "; getline(cin, name);
            gotoxy(10, 8); cout << "Birthday (MM/DD/YYYY): "; getline(cin, bday);
            gotoxy(10, 9); cout << "Contact Number       : "; getline(cin, contact);
		
			do {
	                gotoxy(10, 10); cout << "Initial Deposit (Min. 5000): P";
	                cin >> initDep;
	                if (initDep < 5000) {
	                    gotoxy(10, 12); cout << "Error: Deposit must be >= P5000! Please try again.";
	                    Sleep(1000);
	                    gotoxy(10, 12); cout << "                                             ";
	                    gotoxy(38, 10); cout << "            ";
	                }
	            } while (initDep < 5000);
	            
	        do {
                gotoxy(10, 11); cout << "Set PIN Code (4-6 Digits)  : ";
                pin = getMaskedPIN(); 

                if (pin.length() >= 4 && pin.length() <= 6) {
                    regSuccess = atmSystem.regAcc(accNum, name, bday, contact, pin, initDep);
                }
                else{
                    gotoxy(10, 13); cout << "Invalid PIN! Must be 4-6 numeric digits. Re-enter.";
                    Sleep(1200);
                    gotoxy(10, 13); cout << "                                                  ";
                    gotoxy(39, 11); cout << "            ";
                }

            } while (!regSuccess);
            
            gotoxy(10, 13); cout << "Your Account and Card has been registered.";
            _getch();
		}
		
		if (!atmSystem.retrieveAccountFile()) {
            system("cls");
            gotoxy(10, 5); cout << "INVALID CARD: account not found or card data mismatch.";
            _getch();
            continue;
        }
		
		
		int attempts = 0;
        bool authenticated = false;

        while (attempts < 3 && !authenticated) {
            system("cls");
            gotoxy(10, 4); cout << "!!!!!! SECURITY AUTHENTICATION !!!!!!";
            gotoxy(10, 6); cout << "Enter ATM PIN Code: ";
            string enteredPIN = getMaskedPIN();

            if (atmSystem.authenticate(enteredPIN)) {
                authenticated = true;
            } else {
                attempts++;
                gotoxy(10, 8); cout << "INVALID PIN! Attempts remaining: " << (3 - attempts);
                _getch();
            }
        }
        
        if (!authenticated) {
            system("cls");
            gotoxy(10, 10); cout << "ACCESS DENIED: Please eject/unplug your card drive...";
            while(Drive() != ""){
                Sleep(500);
            }
            continue;
        }
        
        bool activeSession = true;
        while (activeSession) {
            system("cls");
            gotoxy(10, 3); cout << "******** > ATM TRANSACTION MENU < ********";
            gotoxy(10, 5); cout << "[1] Balance Inquiry";
            gotoxy(10, 6); cout << "[2] Withdraw Cash";
            gotoxy(10, 7); cout << "[3] Deposit Cash";
            gotoxy(10, 8); cout << "[4] Fund Transfer";
            gotoxy(10, 9); cout << "[5] Change PIN Code";
            gotoxy(10, 10); cout << "[6] Exit & Eject Card";
            gotoxy(10, 12); cout << "Select Option: ";

            char choice = _getch();
            
            switch (choice) {
                case '1': {
                    system("cls");
                    stringstream ss;
                    ss << fixed << setprecision(2) << atmSystem.balanceInquiry();
                    receipt("BALANCE INQUIRY", "Current Balance  : P" + ss.str(), "", "Press any key to return to menu...");
                    break;
                }

                case '2': {
                    float am;
                    system("cls");
                    gotoxy(10, 4); cout << "******** > CASH WITHDRAWAL < ********";

                    do {
                        gotoxy(10, 6); cout << "Enter Amount (Multiples of 100): P";
                        cin >> am;

                        if (am < 100 || am > atmSystem.balanceInquiry() || (int)am % 100 != 0) {
                            gotoxy(10, 8); cout << "Invalid Amount/Insufficient Balance! Try again.";
                            Sleep(1200);
                            gotoxy(10, 8); cout << "                                                ";
                            gotoxy(44, 6); cout << "               ";
                        }
                    } while (am < 100 || am > atmSystem.balanceInquiry() || (int)am % 100 != 0);

                    string pin;
                    if (atmSystem.verifyTransactionPIN(7, pin)) {
                        if (atmSystem.withdraw(am, pin)) {
                            stringstream ss1, ss2;
                            ss1 << fixed << setprecision(2) << am;
                            ss2 << fixed << setprecision(2) << atmSystem.balanceInquiry();
                            receipt("WITHDRAWAL", "Amount Withdrawn : P" + ss1.str(), "Remaining Bal    : P" + ss2.str(), "Withdrawing Cash... Press any key to continue.");
                        }
                    } else {
                        system("cls");
                        gotoxy(10, 8); cout << "MAX PIN ATTEMPTS EXCEEDED! Ejecting Card...";
                        gotoxy(10, 10); cout << "Please eject/unplug your card drive...";
                        while(Drive() != ""){ Sleep(500); }
                        activeSession = false;
                    }
                    break;
                }

                case '3': {
                    float am;
                    system("cls");
                    gotoxy(10, 4); cout << "******** > CASH DEPOSIT < ********";

                    do {
                        gotoxy(10, 6); cout << "Enter Deposit Amount: P";
                        cin >> am;

                        if (am <= 0) {
                            gotoxy(10, 8); cout << "Error: Amount must be more than 0! Please try again.";
                            Sleep(1000);
                            gotoxy(10, 8); cout << "                                     ";
                            gotoxy(33, 6); cout << "            ";
                        }
                    } while (am <= 0);

                    string pin;
                    if (atmSystem.verifyTransactionPIN(7, pin)) {
                        if (atmSystem.deposit(am, pin)) {
                            stringstream ss1, ss2;
                            ss1 << fixed << setprecision(2) << am;
                            ss2 << fixed << setprecision(2) << atmSystem.balanceInquiry();
                            receipt("DEPOSIT", "Amount Deposited : P" + ss1.str(), "New Balance      : P" + ss2.str(), "Deposit Success! Press any key to continue.");
                        }
                    } else {
                        system("cls");
                        gotoxy(10, 8); cout << "MAX PIN ATTEMPTS EXCEEDED! Ejecting Card...";
                        gotoxy(10, 10); cout << "Please eject/unplug your card drive...";
                        while(Drive() != ""){ Sleep(500); }
                        activeSession = false;
                    }
                    break;
                }

                case '4': {
                    string destAcc;
                    float am;
                    system("cls");
                    gotoxy(10, 4); cout << "******** > FUND TRANSFER < ********";
                    gotoxy(10, 6); cout << "Target 5-Digit Acc No: "; cin >> destAcc;

                    do {
                        gotoxy(10, 7); cout << "Transfer Amount      : P"; cin >> am;
                        if (am < 100 || am > atmSystem.balanceInquiry()) {
                            gotoxy(10, 9); cout << "Invalid amount or insufficient funds! Please try again.";
                            Sleep(1200);
                            gotoxy(10, 9); cout << "                                                ";
                            gotoxy(34, 7); cout << "            ";
                        }
                    } while (am < 100 || am > atmSystem.balanceInquiry());

                    string pin;
                    if (atmSystem.verifyTransactionPIN(8, pin)) {
                        if (atmSystem.transfer(destAcc, am, pin)) {
                            stringstream ss1, ss2;
                            ss1 << fixed << setprecision(2) << am;
                            ss2 << fixed << setprecision(2) << atmSystem.balanceInquiry();
                            receipt("FUND TRANSFER (Target: " + destAcc + ")", 
                                    "Amount Transferred: P" + ss1.str(), 
                                    "New Balance      : P" + ss2.str(), 
                                    "Transfer Complete! Press any key to continue.");
                        } else {
                            gotoxy(10, 10); cout << "FAILED: Destination Account missing.";
                            _getch();
                        }
                    } else {
                        system("cls");
                        gotoxy(10, 8); cout << "MAX PIN ATTEMPTS EXCEEDED! Ejecting Card...";
                        gotoxy(10, 10); cout << "Please eject/unplug your card drive...";
                        while(Drive() != ""){ Sleep(500); }
                        activeSession = false;
                    }
                    break;
                }

                case '5': {
                    system("cls");
                    gotoxy(10, 4); cout << "******** > CHANGE PIN CODE < ********";
                    gotoxy(10, 6); cout << "Current PIN : "; string oldPin = getMaskedPIN();
                    gotoxy(10, 7); cout << "New PIN     : "; string newPin = getMaskedPIN();
                    gotoxy(10, 8); cout << "Confirm PIN : "; string confirmPin = getMaskedPIN();

                    if (atmSystem.pinChange(oldPin, newPin, confirmPin)) {
                        gotoxy(10, 10); cout << "SUCCESS: PIN updated!";
                    } else {
                        gotoxy(10, 10); cout << "FAILED: Verification or bad PIN length.";
                    }
                    getch();
                    break;
                }

                case '6':
                    system("cls");
                    gotoxy(10, 5); cout << "Please eject/unplug your card drive...";
                    while(Drive() != ""){
                        Sleep(500);
                    }
                    activeSession = false;
                    system("cls");
                    gotoxy(10, 5); cout << "Card Ejected. Thank you for using our ATM!";
                    getch();
                    break;
                
                default:
                	cout << "Invalid Choice! Please select an option from the menu and try again" << endl;
                    _getch();
                	break;
            }
    	}
	}
}