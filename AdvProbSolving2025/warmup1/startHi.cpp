
// Given a string, return true if the string starts with "hi" and false otherwise.


// startHi("hi there") → true
// startHi("hi") → true
// startHi("hello hi") → false

#include <iostream>

using namespace std;

int main()
{
    string s = "hi there";
    cout<<((s.substr(0, 2) == "hi") ? "true" : "false")<<endl;

    return 0;
}