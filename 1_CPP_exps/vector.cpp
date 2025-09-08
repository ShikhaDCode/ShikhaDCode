#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    cout<<v.size()<<endl;
    cout << v.capacity() << endl;

    v.push_back(7);
    
    cout<<v.size()<<endl;
    cout << v.capacity() << endl;

    v.pop_back();

    cout<<v.size()<<endl;
    cout << v.capacity() << endl;

    for(auto i : v)
    {
        cout<<i<<" ";
    }

    cout<<endl;
    return 0;
}