#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void MyReverse(vector<int>& v)
{
    int size = v.size();
    for(int i = 0; i < size / 2; i++){
        swap(v[i], v[size - i - 1]);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    MyReverse(v);

    for(auto& i : v){
        cout << i << " ";
    }

    cout << endl;

    // vector<int> v2 = {10, 20, 30, 40, 50};
    // std::reverse(v2.begin(), v2.end());

    // for(auto& i : v2){
    //     cout << i << " ";
    // }

    // cout << endl;

    return 0;
}