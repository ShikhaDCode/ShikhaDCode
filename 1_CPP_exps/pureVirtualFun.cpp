#include <iostream>
#include <memory>
using namespace std;

class Vehicle {
public:
    virtual void ShowVehicle() = 0;
};

class Car : public Vehicle {
public:
    void ShowVehicle() override {
        cout << "This is a car" << endl;
    }
};

class Bus : public Vehicle {
public:
    void ShowVehicle() override {
        cout << "This is a Bus" << endl;
    }
};

int main() {
    Vehicle* v1 = new Car();
    unique_ptr<Vehicle> v2 = make_unique<Car>();
    
    v1->ShowVehicle();
    v2->ShowVehicle();

    return 0;
}