#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

class Person{
    unique_ptr<char[]> name;
public:
    Person() = default;
    Person(char* str){
        name = make_unique<char[]>(strlen(str) + 1);
        strcpy(name.get(), str);
        cout << "Constructor is called\n";
    }

    Person(const Person& other){
        name = make_unique<char[]>(strlen(other.name.get()) + 1);
        strcpy(name.get(), other.name.get());
        cout << "Copy constructor is called\n";
    }

    Person& operator=(const Person& other){
        cout << "Assignment operator called\n";
        if(this != &other){
            name = make_unique<char[]>(strlen(other.name.get()) + 1);
            strcpy(name.get(), other.name.get());
            return *this;
        }

        return *this;
    }


    void Display(){
        cout << "My name is " << name.get() << endl;
    }
};

int main()
{
    char str[] = "Shikha";
    Person p1(str);
    Person p2(p1);
    Person p3;
    p3 = p2;

    p1.Display();
    p2.Display();
    p3.Display();

    return 0;

}