#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int tmp;

    cout << "Insert Elements in vector:" << endl;

    for(int i = 0; i < 7; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    tmp = v[0];
    for(int i = 1; i < 7; i++){
        tmp ^= v[i];
    }

    cout << "Odd occr: " << tmp << endl;

    return 0;
}