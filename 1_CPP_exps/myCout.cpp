#include<iostream>
using namespace std;

template <typename T>
class MyOstream{
    T data;

public:
    MyOstream(T value) : data(value) {}
    MyOstream& operator<<(const T& val){
        cout << val;
        return *this;
    }
};

int main()
{
    MyOstream<int> myCout(10);

    myCout << 20 << 5;

    return 0;
}