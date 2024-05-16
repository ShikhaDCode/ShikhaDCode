#include <iostream>

using namespace std;

void ShowBits(int num)
{
    while(num){
        if(num & 1){
            cout << "1 ";
        } else {
            cout << "0 ";
        }

        num >>= 1;
    }

    cout << endl;
}

bool IsPowerOfTwo(int num)
{
    if(num & (num - 1)){
        return false;
    } else {
        return true;
    }
}

int main()
{
    int num = 0;

    cout << "Enter the number: "<< endl;
    cin >> num;

    ShowBits(num);
    if(IsPowerOfTwo(num))
    {
        cout << "Power of 2\n";
    } else {
        cout << "Not power of 2" << endl;
    }

    return 0;
}