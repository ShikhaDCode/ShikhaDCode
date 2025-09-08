#include <iostream>
#include <memory>

using namespace std;

class Vehicle {
public:
    int years;
    int fuel;

    Vehicle(int a, int b){
        cout << "Constructor called" << endl;
        years = a;
        fuel = b;
    }

    void ShowVehicle(){
        cout << "this vehicle is " << years << " old\n";
        cout << "It has " << fuel << " ltr fuel currently\n";
    }

    ~Vehicle(){
        cout << "Destructor called" << endl;
    }
};

int main()
{
    shared_ptr<Vehicle> v = make_shared<Vehicle>(1, 20);
    shared_ptr<Vehicle> v2 = v;

    v->ShowVehicle();
    v2->ShowVehicle();

    return 0;

}