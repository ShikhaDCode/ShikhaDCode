#include<iostream>
#include<vector>

using namespace std;

void MergeTwoSortedArray(vector<int>& v1, vector<int>& v2)
{
    vector<int> merged;
    int i = 0, j = 0;

    while((i <= v1.size()) && (j <= v2.size()))
    {
        merged.push_back(v1[i++]);
        merged.push_back(v2[j++]);
    }

    while(i <= v1.size()){
        merged.push_back(v1[i++]);
    }

    while(j <= v2.size()){
        merged.push_back(v2[j++]);
    }

    for(auto a : merged){
        cout << a << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {5, 6, 7, 8, 9, 10};

    MergeTwoSortedArray(v1, v2);

    return 0;
}