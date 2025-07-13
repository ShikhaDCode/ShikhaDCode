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

int main()
{
    string st = "heyy!";
    PrintMsg([](string& msg){cout << msg << endl;});
    PrintStdFunction([](string& msg){cout << msg << endl;}, st);
    return 0;
}
