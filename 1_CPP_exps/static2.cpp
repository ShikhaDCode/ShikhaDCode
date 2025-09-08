#include<iostream>

using namespace std;

class Test {
public:
    Test& Increment();
private:
    static int count;
};

int Test::count = 0;

Test& Test::Increment()
{
    count++;
    cout << count << " ";
    return *this;
}

int main()
{
    Test t;
    t.Increment().Increment().Increment().Increment();

    return 0;
}