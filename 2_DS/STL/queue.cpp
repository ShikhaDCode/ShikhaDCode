#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

void ShowData(queue<string>& d)
{

    queue<string> st(d);

    for(int i = 0; i < d.size(); i++){
        cout << st.front() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    queue<string> str;

    str.push("hey");
    str.push("Hi");
    str.push("This");
    str.push("is");
    str.push("Shikha");

    ShowData(str);

    return 0;
}