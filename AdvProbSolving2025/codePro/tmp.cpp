#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int, string> myMap;

    myMap[1] = "one";
    myMap[2] = "two";

    cout<<"key at index 1"<<myMap[1]<<endl;

    for(auto& pair : myMap){
        cout<<pair.first<<"-->"<<pair.second<<endl;
    }

    return 0;
}