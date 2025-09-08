// #include <iostream>
// #include<string>
// using namespace std;

// class Base
// {
// public:
//     virtual string print() const
//     {
//         return "This is Base class";
//     }
// };

// class Derived : public Base
// {
// public:
//     virtual string print() const
//     {
//         return "This is Derived class";
//     }
// };

// void describe(Base* p)
// {
//     cout << p->print() << endl;
// }

// int main()
// {
//     Base b;
//     Derived d;
//     describe(&b);
//     describe(&d);
//     return 0;
// }


// #include<iostream>
// using namespace std;

// class Base {
// public:
//     void fun()          {    cout << "Base::fun() called";     }
//     void fun(int i)     {   cout << "Base::fun(int i) called";  }
// };

// class Derived: public Base  {
// public:
//     void fun()   {     cout << "Derived::fun() called";   }
// };

// int main()  {
//     Derived d;
//     d.Base::fun(5);
//     // d.fun(5);
//     return 0;
// }



#include<iostream>
using namespace std;

class Base
{
public:
    void show()
    {
        cout<<" In Base ";
    }
};

class Derived: public Base
{
public:
    int x;
    void show()
    {
        cout<<"In Derived ";
    }
    Derived()
    {
        x = 10;
    }
};

int main(void)
{
    Base *bp, b;
    Derived d;
    bp = &d;
    bp->show();
    cout << bp->x;    
    return 0;
}
