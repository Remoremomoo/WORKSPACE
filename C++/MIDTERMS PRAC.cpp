#include <iostream>
using namespace std;

class Vehicle{
protected:
    string brand;
    int speed;
public:
    Vehicle(int n, string m){
        speed = n;
        brand = m;
    }
    void showInfo(){
        cout<<"Car Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<endl;
    }
};

class Motorcycle : public Vehicle{
public:
    bool SideCar;
    Motorcycle(int sp, string br, bool sc) : Vehicle(sp, br){
        brand = br;
        speed = sp;
        SideCar = sc;
    }
    void showInfo(){
        cout<<"Car Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<endl;
        cout<<"Has Sidecar? "<<(SideCar ? "Yes" : "No")<<endl;
    }
};

int main(){
    Motorcycle m(95, "Honda", true);
    m.showInfo();

    return 0;
}
