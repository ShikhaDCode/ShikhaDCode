#include <bits/stdc++.h>
using namespace std;

int searchRotated(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;

        // Left half sorted
        if (a[lo] <= a[mid]) {
            if (a[lo] <= target && target < a[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else { // Right half sorted
            if (a[mid] < target && target <= a[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> v{4,5,6,7,0,1,2};
    cout << searchRotated(v, 0) << "\n";  // -> 4
    cout << searchRotated(v, 3) << "\n";  // -> -1
    cout << searchRotated(v, 2) << "\n";  // -> 6
    return 0;
}
