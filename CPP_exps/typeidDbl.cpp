#include <iostream>
#include <typeinfo>

int main() {
    double d = 3.14;
    int val = 5;
    std::cout << "Type of d: " << typeid(d).name() << '\n';
    std::cout << "Type of val: " << typeid(val).name() << '\n';

    return 0;
}
