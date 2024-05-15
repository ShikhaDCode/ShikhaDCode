#include <iostream>

using namespace std;

bool IsPrime(int num)
{
    if(num == 1)
    {
        return false;
    }

    if((num == 2) || (num == 3))
    {
        return true;
    }

    if(((num % 2) == 0) || ((num % 3) == 0))
    {
        return false;
    }

    for(int i = 5; i * i <= num; i++)
    {
        if((num % i) == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int num = 0;
    bool prime;

    cout << "Enter the number: " << endl;
    cin >> num;

    prime = IsPrime(num);

    if(prime) {
        cout << "prime number" << endl;
    }
    else{
        cout << "Not a Prime Number" << endl;
    }

    return 0;
}