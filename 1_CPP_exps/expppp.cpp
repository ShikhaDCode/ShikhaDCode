#include<iostream>

using namespace std;

class MyString {
public:
    string str;

    MyString(string s) : str(s) {
        cout << "Constructor called" << endl;
    }

    MyString(const MyString& other) {
        str = other.str;
        cout << "Copy constructor called" << endl;
    }

    MyString(MyString&& other) {
        str = move(other.str);
        cout << "Move constructor called" << endl;
    }

    ~MyString() {
        cout << "Destructor called" << endl;
    }
};

MyString StrCreate()
{
    string str("Hi");
    MyString obj(str);
    return move(obj);
}

int main()
{
    MyString ob = StrCreate();
    return 0;
}