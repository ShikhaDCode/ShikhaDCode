#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void FindDuplicates(vector<int>& v)
{
    unordered_map<int, int> umap;

    for(int x : v) {
        umap[x]++;
    }

    for(auto m : umap){
        if(m.second > 1) {
            cout << m.first << endl;
        }
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 3, 1};

    FindDuplicates(v);

    return 0;
}
