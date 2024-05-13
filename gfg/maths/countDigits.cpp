#include <iostream>

using namespace std;

int main()
{
    int num;
    unsigned d = 0;

    cout << "enter the number:" << endl;
    cin >> num;

    while(num){
        d++;
        num /= 10;
    }

    cout << "number of digits: " << d << endl;

    return 0;
}