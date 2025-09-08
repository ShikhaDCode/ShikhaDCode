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

bool IsBitSet(int num, int k)
{
    if(num & (1 << k))
    {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int num = 0;
    int k = 0;

    cout << "Enter the number and position: "<< endl;
    cin >> num >> k;

    ShowBits(num);
    cout << "Bit " << k << " is: "<< IsBitSet(num, k) << endl;

    return 0;
}