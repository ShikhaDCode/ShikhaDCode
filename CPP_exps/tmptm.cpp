#include<iostream>

using namespace std;

class Base {
public:
    virtual void Show() {
        cout << "This is base class\n";
    }
};

class Derived : public Base {
public:
    void Show() override {
        cout << "This is derived class\n";
    }

    void Print() {
        cout << "Printing the message\n";
    }

    int var = 10;
};

int main()
{
    Base *b = new Derived();


    b->Show();

    Derived *d = dynamic_cast<Derived*>(b);

    d->Print();
    cout << d->var << endl;

    cout << "......................" << endl;

    Derived dob;
    Base& bobj = dob;

    bobj.Show();
    
    Derived& dd = dynamic_cast<Derived&>(bobj);
    dd.Print();

    return 0;
}