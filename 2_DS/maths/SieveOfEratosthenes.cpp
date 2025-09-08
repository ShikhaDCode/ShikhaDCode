#include <iostream>
#include <vector>
using namespace std;

//25
void Sieve(int num)
{
    vector<bool> isPrime(num + 1, true);

    for(int i = 2; i <= num; i++){
        if(isPrime[i]){
            cout << i << " ";
            for(int j = i * i; j <= num; j = j + i){
                isPrime[j] = false;
            }
        }
    }

    for(auto i:isPrime){
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    int num = 0;

    cout << "Enter the number: " << endl;
    cin >> num;

    Sieve(num);
    return 0;
}