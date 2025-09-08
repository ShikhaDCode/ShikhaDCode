/*
Given a string, return a new string where the last 3 chars are now in upper case. 
If the string has less than 3 chars, uppercase whatever is there. Note that str.toUpperCase() 
returns the uppercase version of a string.


endUp("Hello") → "HeLLO"
endUp("hi there") → "hi thERE"
endUp("hi") → "HI"
*/

#include <iostream>

using namespace std;

int main()
{
    string s = "Hello";
    string res = "";

    if(s.size() < 3){
        res = s;
    } else {
        res = s.substr(0, s.size() - 3) + s.substr(s.size() - 3, 3).c_str();
    }

    cout<<res<<endl;

    return 0;
}