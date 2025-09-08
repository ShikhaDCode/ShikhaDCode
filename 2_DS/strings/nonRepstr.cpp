#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

void FirstNonRepeating(string& str){
    if(str.empty())
    {
        cout << "error!"<< endl;
        return;
    }
    
    unordered_map<char, int> umap;
    for(auto& a : str){
        umap[a]++;
    }
    
    for(int i = 0; i < umap.size(); i++){
        if(umap[str[i]] == 1){
            cout<<str[i]<<endl;
            return;
        }
    }
}

int main()
{
    string str = "StrisgtgiSk";
    FirstNonRepeating(str);
    
    // cout << str << endl;
    
    return 0;
}