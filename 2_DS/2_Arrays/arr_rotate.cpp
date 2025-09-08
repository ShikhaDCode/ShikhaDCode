#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void RightRotate(vector<int>& v, int n)
{
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + n);
    reverse(v.begin() + n, v.end());
}

void LeftRotate(vector<int>& v, int n)
{
    reverse(v.begin(), v.begin() + n);
    reverse(v.begin() + n, v.end());
    reverse(v.begin(), v.end());
}

void ShowVector(vector<int>& v)
{
    for(int& i : v){
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};

    // RightRotate(v, 3);

    LeftRotate(v, 3);

    ShowVector(v);

    return 0;
}

// int main() {
//     vector<int> v = {1, 2, 3, 4, 5};

//     cout << "Original: ";
//     ShowVector(v);

//     // Left rotate by 2
//     rotate(v.begin(), v.begin() + 2, v.end());
//     cout << "Left Rotate by 2: ";
//     ShowVector(v);

//     // Right rotate by 2 (undoing the left rotation)
//     rotate(v.begin(), v.end() - 2, v.end());
//     cout << "Right Rotate by 2: ";
//     ShowVector(v);

//     return 0;
// }