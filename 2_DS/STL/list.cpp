#include<iostream>
#include<list>

using namespace std;

void ShowData(list<int>& d)
{
    for(int& i : d){
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    ShowData(l);

    l.push_front(0);
    l.push_front(-1);
    l.push_front(-2);
    l.push_front(-3);
    l.push_front(-4);
    l.push_front(-5);
    l.push_front(-6);

    ShowData(l);

    l.pop_front();
    l.pop_back();

    ShowData(l);
    return 0;
}