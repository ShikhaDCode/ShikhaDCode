#include <iostream>

using namespace std;

// void func(int a)
// {
//     cout << "Hello " << a << endl;
// }

// int main()
// {
//     void (*callback)(int) = func;
//     callback(5);

//     return 0;
// }

typedef int (*func)(int, int);

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    return a / b;
}

void calc(int a, int b, func f1)
{
    int ret = f1(a, b);
    cout << "result: " << ret << endl;
}

int main()
{
    calc(2, 3, add);
    calc(2, 3, sub);
    calc(2, 3, mul);
    calc(2, 3, division);

    return 0;
}