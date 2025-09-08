// Given a string, count the number of words ending in 'y' or 'z' -- so the 'y' in "heavy" 
// and the 'z' in "fez" count, but not the 'y' in "yellow" (not case sensitive). 
// We'll say that a y or z is at the end of a word if there is not an alphabetic letter
//  immediately following it. (Note: Character.isLetter(char) tests if a char 
//  is an alphabetic letter.)

// countYZ("fez day") → 2
// countYZ("day fez") → 2
// countYZ("day fyyyz") → 2

// #include <iostream>
// #include <string>
// #include <sstream>

#include<bits/stdc++.h>

using namespace std;

int countXZ(std::string& str)
{
    std::stringstream stm(str);
    std::string word;
    int count = 0;

    while(stm >> word){
        if((word[word.length() - 1] == 'y') || (word[word.length() - 1] == 'z'))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int ret = 0;
    std::string str("fez day");

    ret = countXZ(str);
    cout<<"Count = "<<ret<<endl;

    return 0;
}