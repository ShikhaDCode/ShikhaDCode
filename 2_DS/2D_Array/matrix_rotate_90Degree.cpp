#include<iostream>

using namespace std;

    // int arr[4][4] = {1, 2, 3, 30,
    //                  4, 5, 6, 60,
    //                  7, 8, 9, 90,
    //                  10, 11, 12, 120};

void MyReverse(int* arr, int n)
{
    for(int i = 0; i < n / 2; i++){
        swap(arr[i], arr[n - i - 1]);
    }
}

void Rotate90(int arr[][4], int n)
{
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    for(int i = 0; i < n; i++){
        MyReverse(arr[i], n);
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

    Rotate90(arr, 4);
    PrintMatrix(arr, 4);

    return 0;
}
