#include<bits/stdc++.h>

using namespace std;    

string strCompression(string s)
{
    string res = "";
    int count = 1;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == s[i + 1]){
            count++;
        } else {
            res += s[i] + to_string(count);
            count = 1;
        }
    }

    return res;
}

int main()
{
    string s = "aaabbccccdd";
    cout<<strCompression(s)<<endl;

    return 0;
}
