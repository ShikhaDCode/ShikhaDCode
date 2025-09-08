#include <iostream>
#include <vector>

using namespace std;

void ShowData(const vector<vector<int>>& v)
{
    for(const auto& x : v){
        for(const auto& n : x){
            cout << n << " ";
        }

        cout << endl;
    }
}

void FindAllCombinations(vector<int>& v)
{
    vector<vector<int>> com;
    int n = v.size();
    unsigned int maxMask = 1u << n;

    for(unsigned int mask = 0; mask < maxMask; mask++){
        vector<int> subset;
        for(int j = 0; j < n; j++){
            if(mask & (1u << j)) {
                subset.push_back(v[j]);
            }
        }
        com.push_back(move(subset));
    }

    ShowData(com);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    FindAllCombinations(v);

    return 0;
}