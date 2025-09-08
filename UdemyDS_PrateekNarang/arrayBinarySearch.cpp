#include <bits/stdc++.h>

using namespace std;

bool BinarySearch(vector<int> &vec, int key)
{
    int mid, l, h;

    l = 0;
    h = vec.size() - 1;
    while(l <= h){
        mid = (l + h) / 2;

        if(vec[mid] == key){
            return 1;
        } else if(vec[mid] < key){
            l = mid + 1;
        } else{
            h = mid - 1;
        }
    }

    return 0;
}

int main()
{
    vector<int> v {1, 2, 7, 88, 90};

    cout << BinarySearch(v, 88) << endl;

    return 0;
}