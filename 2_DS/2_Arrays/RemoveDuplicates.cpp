//remove duplicates from sorted array
#include<iostream>
#include<map>
#include<vector>

using namespace std;

void RemoveDups(vector<int>& v)
{
    int j = 0;

    for(int i = 0; i < v.size(); i++) {
        if(v[i] != v[j]) {
            v[++j] = v[i];
        }
    }

    v.resize(j + 1);
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
