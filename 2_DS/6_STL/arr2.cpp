#include <iostream>
#include<array>

using namespace std;

int main()
{
    array<int, 4> a = {1, 2, 3, 4};

    for(auto x : a) {
        cout << x << " ";
    }

    cout << endl;

    cout << a[1] << endl;

    cout << "size = " << a.size() << endl;
    cout << "Front = " << a.front() << endl;
    cout << "Back = " << a.back() << endl;
    cout << "Data = " << a.data() << endl;
    return 0;
}