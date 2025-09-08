#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int x = 10;
    double y = 3.14;
    string s = "Hello";

    cout << "Type of x: " << typeid(x).name() << endl;
    cout << "Type of y: " << typeid(y).name() << endl;
    cout << "Type of s: " << typeid(s).name() << endl;

    return 0;
}


// Type of x: i
// Type of y: d
// Type of s: Ss