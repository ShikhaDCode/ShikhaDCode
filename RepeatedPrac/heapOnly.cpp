#include<iostream>

using namespace std;

class HeapOnly {
private:
    int value;
    HeapOnly(int val) : value(val)
    {
        value = val;
    }

    HeapOnly(const HeapOnly& obj) = delete;
    HeapOnly operator=(const HeapOnly& obj) = delete;
public:
    static HeapOnly* CreateObj(int val)
    {
        return new HeapOnly(val);
    }

    void ShowValue()
    {
        cout << "Value = " << value << endl;
    }

    ~HeapOnly(){
        cout << "Destructor called\n";
    }
};

int main()
{
    HeapOnly* hp = HeapOnly::CreateObj(10);
    hp->ShowValue();

    delete hp;

    return 0;
}