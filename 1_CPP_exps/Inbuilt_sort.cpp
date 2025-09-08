#include<bits/stdc++.h>
// #include<algorithm>

using namespace std;

bool compare(int a, int b){
    cout<<"Comparing "<<a<<" and "<<b<<endl;
    return a > b;
}

int main()
{
    int arr[] = {1, 3, 2, 4, 6, 5, 7};
    vector<int> v = {1, 3, -2, 4, 6, -13, 12};

    sort(v.begin(), v.end());
    
    // sort(v.begin(), v.end(), compare);

    // sort(v.begin(), v.end(), greater<int>());

    // sort(v.begin(), v.end(), [](int a, int b){
    //     return abs(a) < abs(b);
    // });

    // sort(v.begin(), v.end(), [](int a, int b){
    //     return a < b;
    // });

    for(auto i : v){
        cout<<i<<" ";
    }

    cout<<endl;
    // sort(arr, arr + 7);

    // sort(arr, arr + 7, greater<int>());

    sort(arr, arr + 7, compare);

    for(auto i : arr){
        cout<<i<<" ";
    }

    cout<<endl;
    reverse(arr, arr + 7);
    for(auto i : arr){
        cout<<i<<" ";
    }
    
    return 0;
}
