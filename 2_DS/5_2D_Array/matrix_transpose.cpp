#include<iostream>

using namespace std;

    // int arr[4][4] = {1, 2, 3, 30,
    //                  4, 5, 6, 60,
    //                  7, 8, 9, 90,
    //                  10, 11, 12, 120};

void Transpose(int arr[][4], int n)
{
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void PrintMatrix(int arr[][4], int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int arr[4][4] = {1, 2, 3, 30,
                     4, 5, 6, 60,
                     7, 8, 9, 90,
                     10, 11, 12, 120};

    Transpose(arr, 4);
    PrintMatrix(arr, 4);

    return 0;
}
