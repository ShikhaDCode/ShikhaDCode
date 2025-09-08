#include<iostream>
#include <functional>

using namespace std;

template <typename Func>
void Execute(Func f, int a, int b)
{
    cout << "This is lambda call\n";
    cout << f(a, b) << endl;
}

void Execute2(std::function<int(int a, int b)> f, int a, int b)
{
    cout << "This is lambda call\n";
    cout << f(a, b) << endl;
}

void Execute3(int (*f)(int a, int b), int a, int b)
{
    cout << "This is lambda call\n";
    cout << f(a, b) << endl;
}

typedef int (*funct)(int a, int b);

void Execute4(funct f, int a, int b)
{
    cout << "This is lambda call\n";
    cout << f(a, b) << endl;
}

int main()
{
     Execute4([](int a, int b){return a + b;}, 4, 5);
     return 0;
}

// int main()
// {
//     auto func = [](int a, int b){
//         return a + b;
//     };

//     cout << func(1, 44) << endl;

//     return 0;
// }