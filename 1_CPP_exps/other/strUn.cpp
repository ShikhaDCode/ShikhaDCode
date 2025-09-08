#include <iostream>

using namespace std;

// #pragma pack(1)

struct St {
    int data;
    float percent;
    char alpha;
};

struct St2 {
    St2() : data(1)
    {
        cout << "hello St2!" << endl;
    }

    ~St2() {
        cout << "Bye Bye" << endl;
    }

    void setData(int val)
    {
        data = val;
    }

    int getData()
    {
        return data;
    }

private:
    int data;
};

union Ut {
    Ut() : data(1)
    {
        cout << "hello St2!" << endl;
    }

    ~Ut() {
        cout << "Bye Bye" << endl;
    }

    void setData(int val)
    {
        data = val;
    }

    int getData()
    {
        return data;
    }

private:
    int data;
};

int main()
{
    // St s1;
    // cout << sizeof(s1) << endl;

    // St2 s2;

    // s2.data = 5;

    // cout << "S2 data = " << s2.data << endl;

    // cout << "s2 data: " << s2.getData() << endl;

    // s2.setData(20);

    // cout << "s2 data: " << s2.getData() << endl;

    Ut u2;

    cout << "u2 data: " << u2.getData() << endl;
    u2.setData(20);
    cout << "u2 data: " << u2.getData() << endl;

    return 0;
}

// #pragma pack()