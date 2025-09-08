#include <iostream>
using namespace std;
void fun(int);
void fun(int, int);
void fun(int i) { cout << "Value of i is : " << i << endl; }
void fun(int a, int b = 9)
{
    cout << "Value of a is : " << a << endl;
    cout << "Value of b is : " << b << endl;
}
int main()
{
    fun(12);

    return 0;
}

// Code Submitted By Susobhan Akhuli


#include <iostream>
using namespace std;
void fun(int);
void fun(int&);
int main()
{
    int a = 10;
    fun(a); // error, which fun()?
    return 0;
}
void fun(int x) { cout << "Value of x is : " << x << endl; }
void fun(int& b)
{
    cout << "Value of b is : " << b << endl;
}

// Code Submitted By Susobhan Akhuli
