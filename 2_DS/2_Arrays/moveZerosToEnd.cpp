#include<iostream>
#include<vector>

using namespace std;

void MoveZerosToEnd(vector<int>& v)
{
    int n = v.size();
    int pos = 0;

    for(int i = 0; i < n; i++) {
        if(v[i] != 0) {
            v[pos++] = v[i];
        }
    }

    if(pos != n) {
        while(pos < n) {
            v[pos++] = 0;
        }
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
    vector<int> vec = {1, 0, 2, 3, 0, 4, 6, 0};

    MoveZerosToEnd(vec);

    ShowData(vec);
    return 0;
}