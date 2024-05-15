#include <iostream>

using namespace std;

int main()
{
    int num = 0, n = 0;

    cout << "Enter the number" << endl;
    cin >> num;
    for(int i = 5; i <= num; i += 5)
    {
        n = n + num/i;
    }

    cout << "Trailing zeros = " << n << endl;

    return 0;
}