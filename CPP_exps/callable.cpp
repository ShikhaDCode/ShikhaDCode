#include <iostream>

using namespace std;

void callback(void (*print)(string& s))
{
    string name = "shikha";
    print(name);
}

int main()
{
    callback([](string& s){
        cout << s << endl;
    });

    //.............................................//
    auto func = [](string& s){
        cout << s << endl;
    };

    callback(func);

    return 0;
}