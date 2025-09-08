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

int main()
{
    int a, b, g;

    cout << "Enter two numbers: " << endl;
    cin >> a >> b;

    g = gcd(a, b);

    cout << "GCD =" << g << endl;
    return 0;
}