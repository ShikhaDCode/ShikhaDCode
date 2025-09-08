#include<iostream>
#include<ctype.h>

using namespace std;

void ShowBits(unsigned int var)
{
    while(var) {
        cout << (var & 1) << " ";
        var >>= 1;
    }
}

int main()
{
    int x = 65;

    // char* y = reinterpret_cast<char*>(&x);
    float* y = reinterpret_cast<float*>(&x);
    char z = static_cast<char>(x);
    ShowBits(x);
    cout << *y << endl;
    ShowBits(*y);
    cout << z << endl;
    ShowBits(z);

    return 0;
}