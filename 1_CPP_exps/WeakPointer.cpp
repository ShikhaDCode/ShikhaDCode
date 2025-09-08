#include<iostream>
#include<memory>

class Node {
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
};

int main()
{
    std::shared_ptr<Node> sptr1 = std::make_shared<Node>();
    std::shared_ptr<Node> sptr2 = std::make_shared<Node>();

    sptr1->next = sptr2;
    sptr2->prev = sptr1;

    return 0;
}