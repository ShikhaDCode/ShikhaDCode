#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void RotateFn(vector<int>& v, int count)
{
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + count);
    reverse(v.begin() + count, v.end());
    // reverse(v.begin(), v.end());
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    RotateFn(v, 2);
    for(auto x : v){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}