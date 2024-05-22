#include <iostream>

using namespace std;

int SumNaturalNums(int n)
{
    if (n == 0){
        return n;
    }

    return n + SumNaturalNums(n - 1);
}

int main()
{
    cout << SumNaturalNums(5) << endl;
    return 0;
}