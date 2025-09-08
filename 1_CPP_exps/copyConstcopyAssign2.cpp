#include<iostream>

using namespace std;

class Vehicle{
    int fuel;
    int years;
public:
    Vehicle(int f, int n) : fuel(f), years(n){
        cout << "parameterised constructor is called\n";
    }
    
    Vehicle() = default;
    
    Vehicle(const Vehicle& veh){
        fuel = veh.fuel;
        years = veh.years;
        cout << "Copy constructor is called\n";
    }
    
    Vehicle& operator=(const Vehicle& v){
        if(this != &v){
            fuel = v.fuel;
            years = v.years;
            cout << "Copy assignment oprator is called\n";
            return *this;
        }
    }
};

int main() {
    Vehicle v1(10, 20);
    Vehicle v2(v1);
    Vehicle v3;
    v3 = v2;

    return 0;
}