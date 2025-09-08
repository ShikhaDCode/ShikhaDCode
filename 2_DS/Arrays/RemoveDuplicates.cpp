//remove duplicates from sorted array
#include<iostream>
#include<map>
#include<vector>

using namespace std;

void RemoveDups(vector<int>& vec)
{
    map<int, int> mp;
    int i = 0;

    for(int e : vec){
        mp[e] = 1;
    }

    vec.resize(mp.size());

    for(auto x : mp){
        vec[i++] = x.first;
    }
}

void ShowData(vector<int>& vec)
{
    for(auto x : vec){
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v = {1, 1, 2, 3, 4, 4, 5, 6, 6, 6};

    RemoveDups(v);

    ShowData(v);

    return 0;
}