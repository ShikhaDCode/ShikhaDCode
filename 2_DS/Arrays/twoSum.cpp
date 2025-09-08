#include<iostream>
#include<utility>
#include<vector>
#include<unordered_map>

using namespace std;

// pair<int, int> TwoSum(vector<int>& vec, int sum)
// {
//     int n = vec.size();

//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             if((vec[i] + vec[j]) == sum) {
//                 return {i, j};
//             }
//         }
//     }

//     return {-1, -1};
// }

pair<int, int> TwoSum(vector<int>& vec, int sum)
{
    unordered_map<int, int> umap;

    for(int i = 0; i < vec.size(); i++)
    {
        int other = sum - vec[i];
        if(umap.find(other) != umap.end()){
            return {umap[other], i};
        }

        umap[vec[i]] = i;
    }

    return {-1, -1};
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    auto result = TwoSum(v, 5);

    cout << result.first << " " << result.second << endl;

    return 0;
}
