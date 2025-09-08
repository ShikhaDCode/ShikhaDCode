#include<iostream>
#include<vector>

using namespace std;

int FindMissingNum(vector<int>& v)
{
    int n = v.size() + 1;
    int sum = 0;

    for(int x : v) {
        sum += x;
    }

    return (((n * (n + 1)) / 2) - sum);
}

int main()
{
    vector<int> v {1, 2, 3, 4, 6, 7, 8};

    cout << "Missing number is : " << FindMissingNum(v) << endl;
    return 0;
}
