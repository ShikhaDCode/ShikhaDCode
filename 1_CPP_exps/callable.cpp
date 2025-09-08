#include<iostream>
#include<functional>

using namespace std;

void PrintMsg(void (*func)(string& msg))
{
    string str = "hello";
    func(str);
}

void PrintStdFunction(std::function<void(string& msg)> func, string& str)
{
    func(str);
}

template <typename Callable>
void PrintMyMsg(Callable func) {
    string str = "hello";
    func(str);
}

struct Functor {
    void operator()(string& msg) {
        cout << "Functor: " << msg << endl;
    }
};


int main()
{
    string st = "heyy!";
    PrintMsg([](string& msg){cout << msg << endl;});
    PrintStdFunction([](string& msg){cout << msg << endl;}, st);
    PrintMyMsg([](string& msg){cout << msg << endl;});
    PrintMsg(Functor{});

    return 0;
}
