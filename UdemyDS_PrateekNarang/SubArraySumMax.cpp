#include <bits/stdc++.h>

using namespace std;

void MaxSubArraySum(vector<int>& v)
{
    int sz = v.size();
    int x, y;
    int cs = 0;
    int max = 0;

    for(int i = 0; i < sz; i++){
        // x = v[i];
        for(int j = i; j < sz; j++){
            // y = v[j];
            // cout << "(" << x << "," << y << ")";
            cs = 0;
            for(int k = i; k <= j; k++){
                cout << v[k] << " ";
                cs += v[k];
            }
            // cout<<endl;
            cout << "\nCurrent Sum:" <<cs <<endl;
            if(max < cs){
                max = cs;
            }
        }
        cout<<endl;
    }

    cout<<"Max sum:"<<max<<endl;
}

void MaxSubArraySumKadane(vector<int>& v)
{
    int vsize = v.size();
    int cs = 0, ms = 0;

    for(int i = 0; i < vsize; i++){
        cs += v[i];
        if(cs < 0){
            cs = 0;
        }

        if(ms < cs){
            ms = cs;
        }
    }

    cout << "Max sum:" << ms <<endl;
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5};
    vector<int> arr {1, 2, 3, 4, 5};

    // for(auto& i : arr){
    //     cout<< i << " ";
    // }

    // cout << endl;

    MaxSubArraySum(arr);
    MaxSubArraySumKadane(arr);

    return 0;
}