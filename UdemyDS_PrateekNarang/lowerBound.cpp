#include<bits/stdc++.h>

using namespace std;

void PrintLowerBound(vector<int>& v, int key)
{
    int mid, s, e, ans;

    s = 0;
    e = v.size() - 1;

    while(s < e){
        mid = (s + e )/2;
        if(v[mid] <= key){
            ans = v[mid];
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    cout<< "Ans:" << ans << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 6, 7};

    PrintLowerBound(arr, 4);

    return 0;
}