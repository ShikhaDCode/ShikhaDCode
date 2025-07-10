#include<iostream>
#include<queue>

using namespace std;

void ShowData(priority_queue<int>& d)
{

    priority_queue<int> st(d);

    for(int i = 0; i < d.size(); i++){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

void ShowDataMin(priority_queue<int, vector<int>, greater<int>>& d)
{

    priority_queue<int, vector<int>, greater<int>> st(d);

    for(int i = 0; i < d.size(); i++){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    priority_queue<int> pq; //max
    priority_queue<int, vector<int>, greater<int>> pqmin;

    pq.push(90);
    pq.push(10);
    pq.push(15);

    ShowData(pq);

    pqmin.push(100);
    pqmin.push(20);
    pqmin.push(45);

    ShowDataMin(pqmin);

    return 0;
}