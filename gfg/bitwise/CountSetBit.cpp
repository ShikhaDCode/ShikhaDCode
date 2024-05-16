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

int CountSetBits(int num)
{
    int res = 0;
    while(num)
    {
        //cout << "while" << endl;
        num = num & (num - 1);
        res++;
    }

    cout << res << endl;
    return res;
}

int main()
{
    int num = 0;

    cout << "Enter the number: "<< endl;
    cin >> num;

    ShowBits(num);
    cout << "Set Bits: "<< CountSetBits(num) << endl;

    return 0;
}