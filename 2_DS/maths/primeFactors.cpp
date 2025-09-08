#include <iostream>

using namespace std;

void PrintPrimeFactors(unsigned int num)
{
    if(num <= 1)
    {
        cout << "No prime factor available" << endl;
    }

    for(int i = 2; i * i <= num; i++){
        while((num % i) == 0) {
            cout << i << " ";
            num /= i;
        }
    }

    if(num > 1)
    {
        cout << num << endl;
    } else {
        cout << endl;
    }
}

int main()
{
    unsigned int num = 0;

    cout << "Enter the number: " << endl;
    cin >> num;

    PrintPrimeFactors(num);

    return 0;
}
