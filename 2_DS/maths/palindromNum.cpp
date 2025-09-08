#include <iostream>

using namespace std;
//1234567654321
int main()
{
    int num, tmp;
    unsigned d = 0;
    int rev = 0;

    cout << "enter the number:" << endl;
    cin >> num;
    tmp = num;
    while(num){
        d++;
        rev = (rev * 10) + (num % 10);
        num /= 10;
    }

    if(tmp == rev){
        cout << "Palindrome"<< endl;
    }
    else{
        cout << "Not Palindrome " << endl;
    }

    return 0;
}