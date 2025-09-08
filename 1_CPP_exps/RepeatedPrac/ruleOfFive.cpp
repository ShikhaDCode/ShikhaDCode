#include<iostream>
#include<memory>
#include<cstring>

using namespace std;

class Vehicle {
public:
    virtual void ShowVehicle() const = 0;
    virtual void SetParameters(int f, int y, const string& str) = 0; // str must be const if string literal or const string is passed like
    virtual ~Vehicle() = default;
protected:
    int fuel{};
    int years{};
    string name;
};

class Car final : public Vehicle {
public:
    Car(int fu, int y, const string& str, const string& f){ // here str and f must be const if string literal is passed
        feature = new char[20];
        strncpy(feature, f.c_str(), f.length());
        SetParameters(fu, y, str);
        cout << "[Car] Constructor called" << endl;
    }

    Car(const Car& other)
    {
        feature = new char[20];
        strncpy(feature, other.feature, sizeof(other.feature));
        fuel = other.fuel;
        years = other.years;
        name = other.name;
        cout << "[Car] Copy Constructor called" << endl;
    }

    Car& operator=(const Car& other)
    {
        if(this != &other){
            delete[] feature;
            feature = new char[20];
            strncpy(feature, other.feature, sizeof(other.feature));
            fuel = other.fuel;
            years = other.years;
            name = other.name;
            cout << "[Car] Copy Assignment operator called" << endl;
        }

        return *this;
    }

    Car(Car&& other) noexcept
    {
        feature = other.feature; 
        /* you don’t need std::move() here because feature is a raw pointer (char*), not a C++ object with move semantics. std::move(ptr) does nothing special for raw pointers.
           It's just a cast to char*& → char*&& (rvalue ref), which doesn’t affect assignment.
           char* assignment is just copying the address.

           So both are equivalent:

           feature = other.feature;          // copies the pointer
           feature = std::move(other.feature); // also copies the pointer
           In both cases, you must still nullify other.feature manually to avoid double-free. 
           
           Use std::move() when:

           The type has move semantics, e.g. std::string, std::vector, std::unique_ptr, etc. */

        other.feature = nullptr;
        fuel = other.fuel;
        years = other.years;
        name = std::move(other.name);
        cout << "[Car] Move constructor called" << endl;
    }

    Car& operator=(Car&& other) noexcept
    {
        if(this != &other){
            delete[] feature;
            feature = new char[20];
            feature = other.feature;
            other.feature = nullptr;
            fuel = other.fuel;
            years = other.years;
            name = move(other.name);
        }

        cout <<" [Car] Move assignment operator called" << endl;
        return *this;
    }

    void ShowVehicle() const override
    {
        cout << "This is Car. With fuel capacity" << fuel << "\n years after purchase: " << years 
            << "\n Name: " << name << endl; 
    }

    void SetParameters(int f, int y, const string& str) override {
        fuel = f;
        years = y;
        name = str;
    }

    void CarSpecificFeatures() const {
        cout << "This car has 5 seats\n";
    }

    ~Car()
    {
        delete[] feature;
        cout << "[Car] Destructor called" << endl;
    }

private:
    char* feature{};
};

int main() {
    cout << "=== Creating Car object (using new) ===\n";
    Vehicle* car = new Car(10, 3, "BMW", "Infotainment");  // Constructor
    car->ShowVehicle();

    cout << "\n=== Copy Constructor on Car ===\n";
    Car* car1 = dynamic_cast<Car*>(car);
    if (car1) {
        Car carCopy(*car1);  // Copy Constructor
    }

    cout << "\n=== Move Constructor on Car ===\n";
    if (car1) {
        Car movedCar(std::move(*car1));  // Move Constructor
    }

    cout << "\n=== Copy Assignment on Car ===\n";
    Car carA(5, 1, "Honda", "Rear camera");
    Car carB(8, 2, "Audi", "Front camera");
    carB = carA;  // Copy Assignment Operator

    cout << "\n=== Move Assignment on Car ===\n";
    Car carC(12, 4, "Skoda", "Music");
    carC = std::move(carA);  // Move Assignment Operator

    delete car;  // Destructor

    cout << "\n=== Creating car object (using unique_ptr) ===\n";
    unique_ptr<Vehicle> car2 = make_unique<Car>(20, 5, "TATA", "Robust");  // Constructor
    car2->ShowVehicle();

    cout << "\n=== Copy Constructor on Car ===\n";
    Car* car2Ptr = dynamic_cast<Car*>(car2.get());
    if (car2Ptr) {
        Car car2Copy(*car2Ptr);  // Copy Constructor
    }

    cout << "\n=== Move Constructor on Car ===\n";
    if (car2Ptr) {
        Car movedCar2(std::move(*car2Ptr));  // Move Constructor
    }

    cout << "\n=== Copy Assignment on Car ===\n";
    Car car2A(30, 8, "Volvo", "Special glass");
    Car car2B(25, 6, "Ashok Leyland", "Smart");
    car2B = car2A;  // Copy Assignment Operator

    cout << "\n=== Move Assignment on Car ===\n";
    Car car2C(35, 10, "Mercedes", "additional seats");
    car2C = std::move(car2A);  // Move Assignment Operator

    cout << "\n=== Exiting main() ===\n";
    return 0;
}
