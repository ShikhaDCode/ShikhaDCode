#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>

using namespace std;

// lock_guard<mutex> lck(mtx);

// unique_lock<mutex> lck(mtx);

// shared_lock<mutex> lck(mtx);

mutex mt;
condition_variable cv;
bool even = false;

void FuncPrintOdd(int limit)
{
    unique_lock<mutex> lck(mt);
    for(int i = 1; i < limit; i+=2) {
        cv.wait(lck, [](){return !even;});

        cout << i << " ";
        even = true;
        cv.notify_one();
    }

}

void FuncPrintEven(int limit)
{
    unique_lock<mutex> lck(mt);
    for(int i = 2; i < limit; i+=2) {
        cv.wait(lck, [](){return even;});

        cout << i << " ";
        even = false;
        cv.notify_one();
    }

}

int main()
{
    thread thOddNum(FuncPrintOdd, 20);
    thread thEvenNum(FuncPrintEven, 20);

    thOddNum.join();
    thEvenNum.join();

    return 0;
}