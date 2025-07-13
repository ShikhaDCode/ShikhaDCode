#include <iostream>
#include <string>

using namespace std;

class Singleton{
public:
    static Singleton& GetInstance(){
        static Singleton obj;
        return obj;
    }

    void PrintMsg(string& str)
    {
        cout << str << endl;
    }
private:
    Singleton(){
    }

    Singleton(const Singleton& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;

};

int main()
{
    Singleton& ob = Singleton::GetInstance();

    return 0;
}

// #include <iostream>
// using namespace std;

// class Singleton {
// private:
//     // Private constructor to prevent direct instantiation
//     Singleton() { 
//         cout << "Singleton Constructor called\n"; 
//     }

//     // Delete copy constructor and copy assignment operator
//     Singleton(const Singleton&) = delete;
//     Singleton& operator=(const Singleton&) = delete;

// public:
//     // Static method to get the single instance
//     static Singleton& getInstance() {
//         static Singleton instance; // Guaranteed to be created once (thread-safe in C++11+)
//         return instance;
//     }

//     void showMessage() {
//         cout << "Hello from Singleton instance!" << endl;
//     }
// };

// int main() {
//     // Accessing the Singleton instance
//     Singleton& s1 = Singleton::getInstance();
//     s1.showMessage();

//     Singleton& s2 = Singleton::getInstance();
//     s2.showMessage();

//     // Check if both references point to the same object
//     if (&s1 == &s2)
//         cout << "Both are the same instance\n";
//     else
//         cout << "Different instances\n";

//     return 0;
// }
