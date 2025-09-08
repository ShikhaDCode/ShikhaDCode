#include<iostream>
#include<deque>

using namespace std;

void ShowData(deque<int>& d)
{
    for(int& i : d){
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    deque<int> d;

    ShowData(d);
    d.push_back(1);
    ShowData(d);
    d.push_front(0);
    ShowData(d);
    d.push_back(2);
    ShowData(d);
    d.push_front(-1);
    ShowData(d);

    d.pop_front();
    ShowData(d);

    d.pop_back();
    ShowData(d);

    cout << "Size: " << d.size() << endl;
    cout << "Empty? : " << d.empty() << endl;

    cout << "d[0] = " << d[1] << endl;

    return 0;
}