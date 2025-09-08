#include <iostream>

using namespace std;

class Vehicle {
    int var1;
    string name;

public:
    Vehicle(int v, string& str) : var1(v), name(str){
        cout << "Constructor called\n";
    }

    Vehicle() = default;
    Vehicle(const Vehicle& other){
        var1 = other.var1;
        name = other.name;
        cout << "Copy constructor called\n";
    }

    Vehicle& operator=(const Vehicle& other){
        var1 = other.var1;
        name = other.name;
        cout << "Copy assignment operator is called\n";
        return *this;
    }
};

int main()
{
    string s = "BMW";
    Vehicle v1(100, s);

    Vehicle v2(v1);
    Vehicle v3;

    v3 = v2;
    Vehicle v4 = v3;
    return 0;
}