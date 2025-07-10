#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

void ShowData(stack<string>& d)
{

    stack<string> st(d);

    for(int i = 0; i < d.size(); i++){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    stack<string> str;

    str.push("hey");
    str.push("Hi");
    str.push("This");
    str.push("is");
    str.push("Shikha");

    ShowData(str);

    return 0;
}