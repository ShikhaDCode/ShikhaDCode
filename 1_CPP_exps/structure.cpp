#include<iostream>

using namespace std;

struct Point {
    int x;
    int y;

    Point(int a, int b) : x(a), y(b) {
        cout << "Constructor called" << endl;
    }

    ~Point(){
        cout << "Destructor called" << endl;
    }
    void Print(){
        cout << "X = " << x << " " << "Y = " << y << endl;
    }
};

int main()
{
    Point p = {10, 20};
    cout << p.x << " " << p.y << endl;

    p.x = 100;
    p.y = 200;
    p.Print();

    return 0;
}