#include <iostream>

using namespace std;

// void add(int a, int b)
// {
//     cout << a + b << endl;
// }

// void add(double a, double b)
// {
//     cout << a + b << endl;
// }

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}


int main()
{
    cout << add(2, 10) << endl;
    cout << add(4.5, 3.1) << endl;

    return 0;
}