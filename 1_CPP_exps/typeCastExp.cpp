#include <iostream>
#include <memory>

using namespace std;

class Vehicle{
protected:
    int fuel;
    int years;
public:
    virtual void ShowVehicle() = 0;
    virtual void SetParameters(int, int) = 0;
    virtual ~Vehicle() {};
};

class Car: public Vehicle {
public:
    void ShowVehicle() override {
        cout << "This is car\n";
    }

    void SetParameters(int a, int b) override{
        fuel = a;
        years = b;
    }

    void CarSpecificFeature(){
        cout << "This car has air conditioning\n";
    }
};

class Bus: public Vehicle {
public:
    void ShowVehicle() override {
        cout << "This is bus\n";
    }

    void SetParameters(int a, int b) override{
        fuel = a;
        years = b;
    }

    void BusSpecificFeature(){
        cout << "This Bus has 50 seats\n";
    }
};

int main()
{
    Vehicle* v = new Car();

    v->SetParameters(10, 3);
    v->ShowVehicle();

    if(Car* c = dynamic_cast<Car*>(v)){
        c->CarSpecificFeature();
    }

    delete v;

    //----------------------------------------------//

    unique_ptr<Vehicle> v2 = make_unique<Bus>();
    v2->ShowVehicle();
    v2->SetParameters(10, 8);

    if(Bus* b = dynamic_cast<Bus*>(v2.get())){
        b->BusSpecificFeature();
    }

    return 0;
}