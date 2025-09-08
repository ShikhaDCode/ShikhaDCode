#include <iostream>
#include <vector>
using namespace std;

int countValidTravelCases(int n, vector<int>& masses) {
    int count = 0;

    // Iterate over all possible starting planets (A)
    for (int A = 0; A < n; A++) {
        int minMass = masses[A]; // Initialize minimum mass for comparison

        // Check travel to planets B > A
        for (int B = A + 1; B < n; B++) {
            // Update the minimum mass seen so far
            minMass = min(minMass, masses[B]);

            // Check if all intermediate planets satisfy the condition
            bool isValid = true;
            for (int i = A + 1; i < B; i++) {
                if (masses[i] >= min(masses[A], masses[B])) {
                    isValid = false;
                    break;
                }
            }

            // If valid, count this pair
            if (isValid) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> masses(n);
    for (int i = 0; i < n; i++) {
        cin >> masses[i];
    }

    cout << countValidTravelCases(n, masses) << endl;

    return 0;
}
