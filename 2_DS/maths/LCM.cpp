#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a, b, l;

    cout << "Enter two numbers: " << endl;
    cin >> a >> b;

    l = lcm(a, b);

    cout << "LCM =" << l << endl;
    return 0;
}