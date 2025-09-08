#include<iostream>
#include<thread>
#include <future>

using namespace std;

void producer(std::promise<int> promise)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    int result = 50;
    promise.set_value(result);
}

int main()
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread t(producer, std::move(promise));
    int result = future.get();
    cout<<"Result:"<<result << endl;

    t.join();
    return 0;
}
