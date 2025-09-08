#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

void FindMinimum(int arr[], int size)
{
    int min = INT_MAX;

    for(int i = 0; i < size; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }

    cout << "Minimum element: " << min << endl;
}

void FindMaximum(vector<int>& v)
{
    int max = INT_MIN;

    for(auto& i : v){
        if(i > max){
            max = i;
        }
    }

    cout << "Maximum element: " << max << endl;
}

int main()
{
    int arr[6] = {1, 4, 2, 6, 8, 9};
    vector<int> v {10, 40, 800, 9, 20, 900};

    FindMaximum(v);
    FindMinimum(arr, 6);

    cout << "With STL library: arr max and min = " 
        << *max_element(arr, arr + 6) << " " 
        << *min_element(arr, arr + 6) << endl;

    cout << "With STL library: vector max and min = " 
        << *max_element(v.begin(), v.end()) << " " 
        << *min_element(v.begin(), v.end()) << endl;

    return 0;
}

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// int main()
// {
//     int arr[6] = {1, 4, 2, 6, 8, 9};
//     vector<int> v {10, 40, 800, 9, 20, 900};

//     cout << "With STL library: arr max and min = " 
//         << *max_element(arr, arr + 6) << " " 
//         << *min_element(arr, arr + 6) << endl;

//     cout << "With STL library: vector max and min = " 
//         << *max_element(v.begin(), v.end()) << " " 
//         << *min_element(v.begin(), v.end()) << endl;

//     return 0;
// }