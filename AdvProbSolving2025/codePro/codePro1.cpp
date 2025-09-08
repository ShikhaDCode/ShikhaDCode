/*
Products of various types are displayed in a row in a home appliance store. However, the positions of sold products have been filled with no planning, so products of the same type have not been placed together. Employee Na Dae-chung intends to remove all the products of the same type and display products of the same type in a row as long as possible.
[Requirement]
At first, employee Na Dae-chung collected and displayed the products of the same type in a row. However, when a new product has been placed in the position of a sold product, the position has been filed with a product randomly, so that now products of different types are mixed up. Employee Na Dae-chung wishes to collect and place products of the same type together again, but it is practically impossible. So, he wishes to remove all the products of one type and place products of the same type in a row.
If there are a number of ways to display the products of the same type in the longest line, he plans to remove all of the products of the type with the highest number from among them.


For example, if 10 products of types 2, 3, and 7 are displayed as shown below, there are three ways to remove those same types.
2 3 3 7 2 7 2 7 3 3
When type 2 is removed, 3 products of type 7 are displayed in a row.
2 3 3 7 2 7 2 7 3 3
When type 3 is removed, there is no product of the same type displayed in a row as shown below. In other words, there is only one
product of the same type. 
2 3 3 7 2 7 2 7 3 3
When type 7 is removed, 2 products of both types 2 and 3 are displayed in a row.
2 3 3 7 2 7 2 7 3 3
When type 2 is removed, 3 products of type 7
are displayed in a row, so this is the best method.
Employee Na Dae-chung intends to find the best method by simulating all possible cases using the above method. Calculating it by hand takes a long time, so he intends to solve it using a program.


[Input format]
In the first line, the number of products N is inputted. (N is an integer, 10 ≤ N ≤ 1,000) In the second line, N product types (ID) are inputted. (ID is an integer, 0 ≤ ID ≤ 1,000,000)
[Output format]
Type of product such that When the products of a this particular type are removed, No. of the product of the same type that is displayed in the maximum length.


Example:
Input
10
2 3 3 7 2 7 2 7 3 3
Output
2

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to calculate the maximum length of consecutive same-type products
int maxConsecutiveLength(vector<int>& arr) {
    int max_length = 1, current_length = 1;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1]) {
            current_length++;
        } else {
            max_length = max(max_length, current_length);
            current_length = 1;
        }
    }
    max_length = max(max_length, current_length);
    return max_length;
}

int main() {
    int N;
    cin >> N;

    vector<int> products(N);
    for (int i = 0; i < N; ++i) {
        cin >> products[i];
    }

    unordered_map<int, int> frequency;
    for (int product : products) {
        frequency[product]++;
    }

    int max_length = 0;
    int target_type = -1;

    for (const auto& entry : frequency) {
        int type_to_remove = entry.first;

        // Create a new array without the current type
        vector<int> filtered_products;
        for (int product : products) {
            if (product != type_to_remove) {
                filtered_products.push_back(product);
            }
        }

        // Calculate the maximum length of consecutive products
        int current_max_length = maxConsecutiveLength(filtered_products);

        // Update the result if we find a better solution
        if (current_max_length > max_length || 
           (current_max_length == max_length && frequency[type_to_remove] > frequency[target_type])) {
            max_length = current_max_length;
            target_type = type_to_remove;
        }
    }

    cout << target_type << endl;

    return 0;
}
