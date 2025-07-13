#include<iostream>
#include<vector>

using namespace std;

void PowerOfTwo(unsigned int n)
{
    if(n & (n - 1)){
        cout << n << " is not power of 2\n";
    } else {
        cout << n << " is power of 2"<< endl;
    }
}

void CountOnes(unsigned int n)
{
    int count = 0;
    int tmp = n;
    while(n) {
        count++;
        n &= n- 1;
    }

    cout << "There are " << count << "  Ones in " << tmp << endl;
}

void NonRepeatingElement(vector<int>& v)
{
    int element = 0;

    for(auto i : v){
        element ^= i;
    }

    cout << element << " is non-repeating element in the vector\n";
}

void TwoNonRepeatingElement(vector<int>& v)
{
    int element = 0;
    int e1 = 0;
    int e2 = 0;
    int bitNum = 0;
    int tmp;

    for(auto i : v){
        element ^= i;
    }

    tmp = element & (-element);

    for(auto i : v){
        if(i & tmp){
            e1 ^= i;
        } else {
            e2 ^= i;
        }
    }

    cout << e1 << " and " << e2 << " are non-repeating elements in the vector\n";
}

int main()
{
    vector<int> v = {1 , 2, 1, 2, 3, 4, 4, 5, 5};
    vector<int> v2 = {1 , 2, 1, 2, 3, 4, 4, 5, 5, 6};
    PowerOfTwo(10);

    CountOnes(15);
    NonRepeatingElement(v);
    TwoNonRepeatingElement(v2);
    return 0;
}