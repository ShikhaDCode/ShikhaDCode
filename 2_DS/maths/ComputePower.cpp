#include <iostream>

using namespace std;

int PowerComp(int x, int num)
{
    int res = 1;
    while(num){
        if(num % 2){
            res *= x;
        }

        x *= x;
        num /= 2;
    }
    
    return res;
}

int main()
{
    int n, p = 0;

    cout << "enter the number and power: "<< endl;
    cin >> n >> p;
    cout << PowerComp(n, p) << endl;

    return 0;
}