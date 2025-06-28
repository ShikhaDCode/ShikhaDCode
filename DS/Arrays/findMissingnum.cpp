#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    vector<int> v(10);
    unordered_map<int, int> umap;

    for(int i = 0; i < v.size(); i++){
        umap[i]++;
    }

    for(auto& i : umap){

    }
}
