#include <iostream>
using namespace std;

// int main() {
//     clog << "Log: Program started successfully." << endl;
//     cout << "This is a normal message." << endl;
//     clog << "Log: Program executed successfully." << endl;

//     return 0;
// }

int main() {
    int x = -1;
    
    if (x < 0) {
        cerr << "Error: x cannot be negative!" << endl;  // Prints immediately
    }

    cout << "This is a normal message." << endl;

    return 0;
}

