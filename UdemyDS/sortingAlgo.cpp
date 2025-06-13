#include <bits/stdc++.h>

using namespace std;

void BubbleSort(vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size(); j++){
            if(vec[j] > vec[j + 1]){
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void InsertionSort(vector<int>& vec)
{
    int current, prev;
    for(int i = 1; i < vec.size(); i++){
        current = vec[i];

        prev = i - 1;
        while(prev >= 0 and vec[prev] > current){
            vec[prev + 1] = vec[prev];
            prev--;
        }

        vec[prev + 1] = current;

    }
}

void SelectionSort(vector<int>& vec)
{
    for(int i = 0;i )
}

int main()
{
    vector<int> vec {1 , 9, 2, 8, 0, 4};

    // BubbleSort(vec);

    InsertionSort(vec);
    for(int x : vec){
        cout << x << " ";
    }

    cout << endl;

    return 0;
}