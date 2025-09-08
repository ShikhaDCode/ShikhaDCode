#include<iostream>

namespace cars {
class Vehicle {
public:
    int pubData;
    Vehicle(int a, int b, int c) : pubData(a), protData(b), privData(c){}

    virtual void ShowData()
    {
        std::cout << "This is a Vehicle\n";
        std::cout << "public data = " << pubData << std::endl;
        std::cout << "Private Data = " << privData << std::endl;
        std::cout << "Protected Data = " << protData << std::endl;
    }
protected:
    int protData;
private:
    int privData;
};

class Car : public Vehicle {
public:
    std::string carOEM;

    Car(std::string oem = "BMW") : Vehicle(10, 20, 30) {
        carOEM = oem;
    }

    void ShowCarOEM() {
        std::cout << "OEM is " << carOEM << std::endl;
        std::cout << "public data = " << pubData << std::endl;
        std::cout << "Protected Data = " << protData << std::endl;
    }

    void ShowData() override
    {
        std::cout << "This is a Car\n";
        std::cout << "OEM is " << carOEM << std::endl;
    }

};
}

int main()
{
    cars::Vehicle vobj(1, 2, 3);
    cars::Car cobj("Toyota");

    vobj.ShowData();
    cobj.ShowCarOEM();
    cobj.ShowData();

    return 0;
}
