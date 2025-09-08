#include<iostream>
#include<vector>

using namespace std;

//{1, 2, 6, 0, 8, 3, 22, 45}

void PrintData(vector<int>& v);
void BubbleSort(vector<int>& v)
{
    int n = v.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j+1]);
            }
        }

        // PrintData(v);
    }
}

//{1, 2, 6, 0, 8, 3, 22, 45} //8
void SelectionSort(vector<int>& v)
{
    int minidx;

    for(int j = 0; j < v.size(); j++){
        minidx = j;
        for(int i = 1 + j; i < v.size(); i++){
            if(v[i] < v[minidx]){
                minidx = i;
            }
        }

        if(minidx != j) {
            swap(v[j], v[minidx]);
        }

        // PrintData(v);
    }

}

void InsertionSort(vector<int>& v)
{
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

void PrintData(vector<int>& v)
{
    for(int i : v){
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 6, 0, 8, 3, 22, 45};

    // BubbleSort(v);
    // SelectionSort(v);
    InsertionSort(v);
    PrintData(v);
    return 0;
}