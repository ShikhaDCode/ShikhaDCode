#include<iostream>
#include<thread>

using namespace std;

int func(int a)
{
    cout << "Inside thread function. Value = " << a << endl;
    return 0;
}

int main()
{
    // int ret = 0;
    std::thread t(func, 40);
    if(t.joinable()){
        t.join();
    }

    std::thread t2([](int a){cout << "Hello from thread! "<< a << endl;}, 40);
    if(t2.joinable()){
        t2.join();
    }


    return 0;
}