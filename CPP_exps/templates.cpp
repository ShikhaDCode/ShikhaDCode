#include<iostream>

using namespace std;

template<typename T>
T Add(T a, T b)
{
    return a + b;
}

template <typename T>
class A {
public:
    T GetVar();
    void SetVar(T val);
private:
    T var;
};

template <typename T>
T A<T>::GetVar()
{
    return var;
}

template <typename T>
void A<T>::SetVar(T val)
{
    var = val;
}

template <>
class A<char> {
public:
    char GetVar();
    void SetVar(char val);
private:
    char var;
};

char A<char>::GetVar()
{
    cout << "Inside GetVar for char type" << endl;
    return var;
}

void A<char>::SetVar(char v)
{
    cout << "Inside SetVar for char type" << endl;
    var = v;
}

int main()
{
    A<int> ob;
    A<char> chob;

    cout << "Function template : Add int result = " << Add(1, 2) << endl;
    cout << "Function template : Add result = " << Add(3.5, 6.1) << endl;

    ob.SetVar(10);
    cout << "Class template : GetVar() " << ob.GetVar() << endl;

    return 0;
}