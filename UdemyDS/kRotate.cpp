#include<bits/stdc++.h>

using namespace std;

void KLeftRotate(vector<int>& vec, int n)
{
    int siz = vec.size() - 1;

    reverse(vec.begin(), vec.begin() + siz - n);
    reverse(vec.begin() + siz - n, vec.end());

    reverse(vec.begin(), vec.end());
}

void KRightRotate(vector<int>& vec, int n)
{
    int siz = vec.size() - 1;

    reverse(vec.begin(), vec.end());
    reverse(vec.begin(), vec.begin() + siz - n);
    reverse(vec.begin() + siz - n, vec.end());

}

int main()
{
    vector<int> vec {1, 2, 3, 4, 5, 6, 7};

    KLeftRotate(vec, 3);

    for(int x : vec){
        cout << x << " ";
    }

    cout << endl;

    KRightRotate(vec, 3);

    for(int x : vec){
        cout << x << " ";
    }

    cout << endl;

    KRightRotate(vec, 3);

    for(int x : vec){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}