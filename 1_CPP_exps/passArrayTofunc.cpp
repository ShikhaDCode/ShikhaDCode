#include<iostream>

using namespace std;

void PrintArray(int arr[], int size)
{
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }

    // cout<<sizeof(arr)<<endl;
    cout<<endl;
}

int main()
{
    int arr[10] = {0};

    PrintArray(arr, 10);

    // cout<<sizeof(arr)<<endl;
    return 0;
}