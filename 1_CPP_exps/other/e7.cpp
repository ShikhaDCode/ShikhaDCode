#include <iostream>

using namespace std;

class Data {
    int i;
    char c;

public:
    Data(int v1, char v2) : i(v1), c(v2)
    {}

    friend void printdata(Data& d);
};

void printdata(Data& d)
{
    cout << "Integer: " << d.i << endl;
    cout << "Char: " << d.c << endl;
}

int main()
{
    Data d1(5, 'a');

    printdata(d1);

    return 0;
}