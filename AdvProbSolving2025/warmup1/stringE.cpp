/*
Return true if the given string contains between 1 and 3 'e' chars.


stringE("Hello") → true
stringE("Heelle") → true
stringE("Heelele") → false
*/

#include <iostream>

using namespace std;

int main()
{
    string s = "Hello";
    int count = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'e'){
            count++;
        }
    }

    cout<<((count >= 1 && count <= 3) ? "true" : "false")<<endl;

    return 0;
}