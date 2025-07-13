#include<iostream>
#include<vector>
#include<climits>
#include<utility>

using namespace std;

pair<int, int> FindLargestSmallest(vector<int>& v)
{
    int min = INT_MAX, max = INT_MIN;

    for(auto x : v){
        if(x < min) {
            min = x;
        }   
    }

    for(auto x : v){
        if(x > max) {
            max = x;
        }    
    }

    // return std::make_pair(min, max);
    return {min, max};
}

int main()
{
    vector<int> v = {1, 2, 3, -10, 5, 7, 90};
    std::pair<int, int> result;
    auto [minv, maxv] = FindLargestSmallest(v);

    // result = FindLargestSmallest(v);
    // cout << "Min = " << result.first << "\nMax = " << result.second << endl;
    cout << "Min = " << minv << "\nMax = " << maxv << endl;
    return 0;
}
