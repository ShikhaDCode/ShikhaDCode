#include<iostream>
#include<vector>

using namespace std;

bool LinearSearch(vector<int> &vec, int key)
{
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == key){
            return 1;
        }
    }

    return 0;
}

int main()
{
    vector<int> v {1, 2, 7, 88, 9};

    cout << LinearSearch(v, 2) << endl;

    return 0;
}