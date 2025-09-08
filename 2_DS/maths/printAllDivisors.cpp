#include<iostream>

using namespace std;

//25
void PrintAllDivisors(int num)
{
    for(int i = 1; i * i <= num; i++)
    {
        if((num % i) == 0)
        {
            cout << i << " ";

            if(i != num/i) {
                cout << "hey! " << num/i << " ";
            }
        }
    }

    cout << endl;
}

int main()
{
    int num = 0;

    cout << "Enter the number: " << endl;
    cin >> num;

    PrintAllDivisors(num);
    return 0;
}