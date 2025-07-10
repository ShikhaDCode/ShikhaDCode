#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 5> arr = {1, 2, 3, 4, 5};
    array<int, 5> brr = {6, 7, 8, 9, 0};

    cout << arr.size() << endl;
    cout << arr.at(2) << " " << arr[2] << endl;

    for(auto& i : arr){
        cout << i << " ";
    }

    cout << endl;

    cout << "empty?  " << arr.empty() << endl;
    cout << arr.front() << "  " << arr.back() << endl;

    arr.swap(brr);
    for(auto& i : arr){
        cout << i << " ";
    }

    return 0;

}