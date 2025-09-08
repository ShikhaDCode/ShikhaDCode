#include<iostream>
#include<vector>

using namespace std;

int FindMissingNum(vector<int>& v)
{
    int n = v.size() + 1;

    int totalSum = (n * (n + 1)) / 2;
    int vecSum = 0;

    for(int x : v){
        vecSum += x;
    }

    return abs(totalSum - vecSum);
}

int main()
{
    vector<int> v = {1, 2, 4, 5, 6, 7};
    cout << FindMissingNum(v) << endl;
    return 0;
}
