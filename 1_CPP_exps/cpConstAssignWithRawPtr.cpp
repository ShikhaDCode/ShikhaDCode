#include <iostream>
#include <cstring>

using namespace std;

class Person {
    char *name;
    
public:
    Person(char *str){
        name = new char[strlen(str) + 1];
        strcpy(name, str);
        cout << "Constructor\n";
    }
    
    Person() = default;

    Person(const Person& other){
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        cout << "Copy constructor\n";
    }
    
    Person& operator=(const Person& other){
        cout << "Copy assignment operator\n";
        if(this != &other){
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            return *this;
        }
        else{
            return *this;
        }
    }
    
    ~Person(){
        delete[] name;
        cout << "destructor\n";
    }
    void Display(){
        cout << "My name is " << name << endl;
    }
};

int main() {
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