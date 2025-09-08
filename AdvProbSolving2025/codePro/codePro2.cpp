/*
Add a number of products to an unbalanced lattice type box to achieve balance in that the sum of the number of products in each row and column is equal.
[Requirement]
The inside of the box is divided into N*N lattices, and each lattice contains several products. The following figure shows the box shape when N is 3 (it is 3x3 array).

|_|_|_|
|_|_|_|
|_|_|_|

We intend to stack the above boxes in the warehouse for storage. However, a random number of products is included in each lattice, so it is impossible to stack them high. Therefore, it is intended to make the sum of the number of products in each row and column of the box equal in order to achieve balance.
At this time, we intend to add more products to achieve balance without removing any product already in place and we intend to minimize the total quantity of products to be added.


For example, if the following products are contained in the box with N=3, we can add 9 products so that the sum of products in each row and column becomes 10, as shown in <Figure 1> below, but

Unbalanced box:
1 2 3 -> 6
4 2 3 -> 9
3 2 1 -> 6
| | |
8 6 7

Balanced box:
1+2 2+1 3+1 -> 10
4     2+1 3     -> 10
3     2+2 1+2 -> 10
|      |      |
10   10    10


we can also achieve balance by adding a total of 6 products so that the sum of each row and column is 9.
Unbalanced box:
1 2 3 -> 6
4 2 3 -> 9
3 2 1 -> 6
|  | |
8 6  7

Balanced box:
1+1 2+1 3+1 -> 9
4     2      3      -> 9
3    2+2 1+1   -> 9
|     |       |
9     9       9

In the example above, adding 9 or 6 products can achieve balance, but since it has been decided to minimize the total quantity of products to be added, 6 is the minimum total quantity of products to be added.
Find the minimum total quantity of products to be added in balancing the box.


[Input format]
In the first line, the size of the box N is inputted (N is an integer, 1 ≤ N ≤ 150)
For the second line, the number of products existing in each lattice separated by a blank and divided by N is inputted over N lines (1 ≤ the number of products = 200)

[Output format]
The minimum total quantity of products to be added to achieve balance is outputted.

Input/Output Example

Input
3
1 2 3
4 2 3
3 2 1

Output
6

TC 1:

3
1 2 3 
4 2 3
3 2 1

6

TC2:


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> box(N, vector<int>(N));
    vector<int> rowSum(N, 0), colSum(N, 0);
    
    // Input the box grid and calculate row sums and column sums
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> box[i][j];
            rowSum[i] += box[i][j];
            colSum[j] += box[i][j];
        }
    }
    
    // Calculate the target value for the rows and columns
    int target = max(*max_element(rowSum.begin(), rowSum.end()),
                     *max_element(colSum.begin(), colSum.end()));
    
    int totalAdd = 0;

    // We will now add products where necessary to achieve the balance
    // Add products to balance rows first
    for (int i = 0; i < N; ++i) {
        if (rowSum[i] < target) {
            totalAdd += target - rowSum[i];
        }
    }

    // Output the total number of products added
    cout << totalAdd << endl;
    
    return 0;
}
