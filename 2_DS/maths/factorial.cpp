#include <iostream>

using namespace std;

int main()
{
    int num, fact = 1;

    cout << "enter the number:" << endl;
    cin >> num;

    for (int i = 2; i <= num; i++){
        fact *= i;
    }

    cout << "Factorial= " << fact << endl;

    return 0;
}