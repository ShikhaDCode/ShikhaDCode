#include<iostream>
#include<vector>

using namespace std;

void MoveZerosToEnd(vector<int>& v)
{
    int endIdx = v.size() - 1;

    while((v[endIdx] == 0) && (endIdx > 0)) {
        if(v[--endIdx] != 0){
            break;
        }
    }

    for(int i = 0; i <= endIdx; i++){
        if(v[i] == 0){
            swap(v[i], v[endIdx]);
            --endIdx;
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