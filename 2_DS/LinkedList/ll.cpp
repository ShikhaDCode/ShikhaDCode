//Linked list

#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
public:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;
    size_t size_;

    LinkedList() : head(nullptr), size_(0){}
    ~LinkedLisst() 
    {
        clear();
    }

    void PushFront(const T& value);
    void PushBack(const T& value);
    void PopFront();
    void PopBack();
    void clear();
    Node* FindNode(const T& value);
    bool Remove(const T& value);
    void Reverse();

};

template <typename T>
void LinkedList<T>::PushFront(const T& value)
{
    Node* tmp = new Node;
    

    
}

int main()
{
    return 0;
}