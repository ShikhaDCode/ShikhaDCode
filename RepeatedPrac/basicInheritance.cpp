#if 0
#include<iostream>
#include<string>
#include<memory>

using namespace std;

class Vehicle {
public:
    virtual void ShowVehicle() const = 0;
    virtual void SetParameters(int f, int y, const string& n) = 0;
    virtual ~Vehicle() = default;
protected:
    int fuel{};
    int years{};
    string name;
};

class Car : public Vehicle {
public:
    void ShowVehicle() const override {
        cout << "This is Car: " << name << ", Fuel: " << fuel << ", Years: " << years << endl;
    }

    void SetParameters(int f, int y, const string& n) override {
        fuel = f;
        years = y;
        name = n;
    }

    void CarSpecificFeatures() const{
        cout << "This car has 5 seats" << endl;
    }
};

class Bus : public Vehicle {
public:
    void ShowVehicle() const override {
        cout << "This is Bus: " << name << ", Fuel: " << fuel << ", Years: " << years << endl;
    }

    void SetParameters(int f, int y, const string& n) override {
        fuel = f;
        years = y;
        name = n;
    }

    void BusSpecificFeatures() const {
        cout << "This bus has 50 seats" << endl;
    }
};

int main()
{
    Vehicle *v = new Car();

    v->SetParameters(10, 3, "BMW");
    v->ShowVehicle();

    if(Car *c = dynamic_cast<Car*>(v)){
        c->CarSpecificFeatures();
    }

    delete v;

    unique_ptr<Vehicle> vh = make_unique<Bus>();
    vh->SetParameters(10, 3, "TATA");
    vh->ShowVehicle();

    if(Bus *b = dynamic_cast<Bus*>(vh.get())){
        b->BusSpecificFeatures();
    }

    return 0;
}
#endif

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Vehicle {
public:
    virtual void ShowVehicle() const = 0;
    virtual void SetParameters(int f, int y, const string& n) = 0;
    virtual ~Vehicle() = default;

protected:
    int fuel{};
    int years{};
    std::string name;
};

class Car : public Vehicle {
public:
    Car(int f, int y, const std::string& n) {
        SetParameters(f, y, n);
    }

    void SetParameters(int f, int y, const string& n) override {
        fuel = f;
        years = y;
        name = n;
    }

    void ShowVehicle() const override {
        cout << "This is Car: " << name << ", Fuel: " << fuel << ", Years: " << years << endl;
    }

    void CarSpecificFeatures() const {
        cout << "This car has 5 seats" << endl;
    }
};

class Bus : public Vehicle {
public:
    Bus(int f, int y, const std::string& n) {
        SetParameters(f, y, n);
    }

    void SetParameters(int f, int y, const string& n) noexcept override {
        fuel = f;
        years = y;
        name = n;
    }

    void ShowVehicle() const noexcept override {
        cout << "This is Bus: " << name << ", Fuel: " << fuel << ", Years: " << years << endl;
    }

    void BusSpecificFeatures() const noexcept {
        cout << "This bus has 50 seats" << endl;
    }
};

int main() {
    // Using raw pointer just for demonstration
    Vehicle* v = new Car(10, 3, "BMW");
    v->ShowVehicle();

    if (Car* c = dynamic_cast<Car*>(v)) {
        c->CarSpecificFeatures();
    }

    delete v;

    // Using unique_ptr (RAII)
    unique_ptr<Vehicle> vh = make_unique<Bus>(20, 5, "TATA");
    vh->ShowVehicle();

    if (Bus* b = dynamic_cast<Bus*>(vh.get())) {
        b->BusSpecificFeatures();
    }

    return 0;
}
