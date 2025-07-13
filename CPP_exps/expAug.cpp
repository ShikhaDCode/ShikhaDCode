#include<iostream>

using namespace std;

class A {
public:
    A(){
        cout << "A: Constructor Called" << endl;
    }

    virtual ~A(){
        cout << "A: Destructor called" << endl;
    }

    virtual void ShowData();
    virtual void PrintMsg();
protected:
    int var1;
private:
    int var2;
};

class B : public A {
public:
    B(){
        cout << "B: Constructor called" << endl;
    }

    ~B(){
        cout << "B: Destructor called" << endl;
    }

    void ShowData() override;
    void PrintMsg() override;
    void Calculate();

private:
    int var3;
    int var4;
};

void A::ShowData()
{
    cout << "Hello I'm class A" << endl;
    cout << "My member variables are: var1 = " << var1 << "var2 =" << var2 << endl;
}

void A::PrintMsg()
{
    cout << "Hello I'm class A, I'm responsible for xyz functionality" << endl;
}

void B::ShowData()
{
    cout << "Hello I'm class B" << endl;
    cout << "My member variables are: var3 = " << var3 << "var4 =" << var4 << endl;
}

void B::PrintMsg()
{
    cout << "Hello I'm class B, I'm responsible for pqr functionality" << endl;
}

void B::Calculate()
{
    cout << "Average = " << (var1 + var3 + var4) / 3 << endl;
}

int main()
{
    A* a = new B();

    a->ShowData();
    a->PrintMsg();

    B* b = dynamic_cast<B*>(a);

    b->Calculate();

    delete a;
    return 0;
}