#include<iostream>
#include<memory>

class Node {
public:
    int data;
    // Node() : data(0) {
    //     std::cout << "Constructor called" << std::endl;
    // }
    Node(int d) {
        std::cout << "Constructor called" << std::endl;
        data = d;
        ShowData();
    }
    ~Node(){
        std::cout << "Destructor called" << std::endl;
    }

    void ShowData(){
        std::cout<<"Data = " << data << std::endl;
    }
};

int main()
{
    std::unique_ptr<Node> ptr1 = std::make_unique<Node>(10);
    std::shared_ptr<Node> ptr2 = std::make_shared<Node>(20);

    ptr1->data = 100;
    ptr1->ShowData();

    ptr2->data = 200;
    ptr2->ShowData();

    return 0;
}