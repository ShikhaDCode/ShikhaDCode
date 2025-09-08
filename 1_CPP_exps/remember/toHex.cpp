#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int num = 255;
    cout << "Binary: " << bitset<8>(num) << endl;
    cout << "Hexadecimal: " << hex << uppercase << num << endl;
    return 0;
}

// #include <iostream>
// #include <sstream>  // Required for stringstream
// using namespace std;

// string intToHex(int num) {
//     stringstream ss;
//     ss << hex << uppercase << num;  // Convert to uppercase hex
//     return ss.str();
// }

// int main() {
//     int num;
//     cout << "Enter an integer: ";
//     cin >> num;

//     cout << "Hexadecimal: " << intToHex(num) << endl;
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int num;
//     cout << "Enter an integer: ";
//     cin >> num;

//     cout << "Hexadecimal: " << hex << num << endl;  // Converts to hex
//     return 0;
// }
