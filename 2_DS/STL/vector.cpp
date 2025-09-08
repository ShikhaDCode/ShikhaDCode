#include <iostream>
#include <vector>

using namespace std;

void ShowVector(vector<int>& v)
{
    for(int& i : v){
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> arr(4, 0);
    vector<int> ab(v);

    ShowVector(v);

    ShowVector(arr);

    ShowVector(ab);

    cout << "Size : " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(2);
    ShowVector(v);

    cout << "Size : " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    cout << v.front() << "  " << v.back() << endl;

    v.pop_back();
    ShowVector(v);

    cout << *v.begin() << "  " << *v.end() << endl;

    v.clear();
    ShowVector(v);

    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    ShowVector(v);

    cout << "Capacity: " << v.capacity() << endl;

    v.shrink_to_fit();

    cout << "Capacity: " << v.capacity() << endl;

    v.resize(6);

    cout << "Capacity: " << v.capacity() << endl;

    v.reserve(100);

    cout << "Capacity: " << v.capacity() << endl;

    v.emplace_back(90);

    ShowVector(v);

    return 0;
}
