#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// std::sort()
int main()
{
    vector<int> vec {1, 2, 5, 0, 9, 3, 27, 15};

    for(int i : vec){
        cout << i << " ";
    }

    cout << endl;

    std::sort(vec.begin(), vec.end());

    for(int i : vec){
        cout << i << " ";
    }

    cout << endl;
}