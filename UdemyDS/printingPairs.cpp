#include <bits/stdc++.h>

using namespace std;

void PrintingPairs(vector<int>& v)
{
    int sz = v.size();
    int x, y;

    for(int i = 0; i < sz; i++){
        x = v[i];
        for(int j = i + 1; j < sz; j++){
            y = v[j];
            cout << "(" << x << "," << y << ")";
        }
        cout<<endl;
    }
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5};
    vector<int> arr {1, 2, 3, 4, 5};

    for(auto& i : arr){
        cout<< i << " ";
    }

    cout << endl;

    PrintingPairs(arr);

    return 0;
}