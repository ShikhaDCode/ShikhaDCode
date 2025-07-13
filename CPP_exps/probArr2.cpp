#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void ReverseArray(vector<int>& v)
{
    // std::reverse(v.begin(), v.end());
    int len = v.size();
    for(int i = 0; i < len/2; i++){
        swap(v[i], v[len - 1 - i]);
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5};

    ReverseArray(v);

    for(auto x : v){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}