#include <iostream>
#include <thread>
#include <vector>

void testStatic() {
    static int x = []{
        std::cout << "Initializing static\n";
        return 42;
    }();
    std::cout << "Value: " << x << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i)
        threads.emplace_back(testStatic);
    for (auto& t : threads)
        t.join();
    return 0;
}
