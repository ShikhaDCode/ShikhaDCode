#include<iostream>
#include<vector>

using namespace std;

pair<int, int> closestSum(vector<int> arr, int x)
{
    int n = arr.size();
    int s = 0, e = n - 1;
    int diff = __INT_MAX__;
    int lIdx, rIdx;

    while(s < e){
        int cs = arr[s] + arr[e];
        if(abs(cs - x) < diff){
            lIdx = s;
            rIdx = e;
            diff = abs(cs - x);
        }
        if(cs > x) {
            e--;
        } else {
            s++;
        }
    }

    return {arr[lIdx], arr[rIdx]};
}

int main()
{
    vector<int> v = {10, 22, 28, 29, 30, 40};
    pair<int, int> p;

    p = closestSum(v, 54);
    cout<< p.first << " " << p.second<< endl;

    return 0;
}