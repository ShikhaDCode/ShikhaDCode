// #include <iostream>
// #include <vector>

// using namespace std;

// void Transpose(vector<vector<int>>& v){
//     int rows = v.size();
//     int cols = v[0].size();

//     vector<vector<int>> transp(cols, vector<int>(rows));

//     for(int i = 0; i < rows; i++){
//         for(int j = 0; j < cols; j++){
//             transp[j][i] = v[i][j];
//         }
//     }

//     for(auto x:transp){
//         for(int a:x){
//             cout<<a<<" ";;
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     vector<vector<int>> v = {
//         {1, 2, 3}, 
//         {4, 5, 6}, 
//         {7, 8, 9}, 
//         {10, 11, 12}};

//     Transpose(v);

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Transpose(vector<vector<int>>& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> transpose(cols, vector<int>(rows));
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            transpose[j][i] = matrix[i][j];
        }
    }
    
    for(auto& x : transpose){
        std::reverse(x.begin(), x.end());
        for(int& a : x){
            cout << a << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> v = {
    {1,2,3}, 
    {4, 5, 6}, 
    {7, 8, 9}, 
    {10, 11, 12}};
    
    Transpose(v);

    return 0;
}

/*
1 2 3
4 5 6
7 8 9
10 11 12


10 7 4 1
11 8 5 2
12 9 6 3

*/