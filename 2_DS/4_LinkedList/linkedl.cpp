#include<iostream>
#include <chrono>
#include <thread>

using namespace std;

template<typename T>
class List {
public:
    struct Node {
        T data;
        Node* next;
        Node() : data(0), next(nullptr) {
            cout << "Node constructor called\n";
        }
        Node(T value) : data(value), next(nullptr) {
            cout << "Node constructor called\n";
        }
    };

    Node *head;
    size_t lsize;

    List() : head(nullptr), lsize(0) {
        cout << "List Constructor called\n";
    }

    void PushBack(const T& value);
    void PushFront(const T& value);
    void PopBack();
    void PopFront();
    Node* FindNode(const T& value);
    void Remove(const T& value);
    void Reverse();
    void Clear();
    void PrintList();
    u_int8_t FindLength()
    {
        return lsize;
    }
    Node* FindMiddle();
    bool HasLoop();
    Node* FindNthFromEnd(int n);
};

template<typename T>
void List<T>::PushBack(const T& value)
{
    cout << "PushBack" << endl;
    if(head == nullptr) {
        head = new Node(value);
    } else {
        Node* tmp = head;

        while(tmp->next){
            tmp = tmp->next;
        }

        tmp->next = new Node(value);
    }

    lsize++;
}

template<typename T>
void List<T>::PushFront(const T& value)
{
    cout << "PushFront" << endl;
    if(head == nullptr)
    {
        head = new Node(value);
    } else {
        Node* tmp = new Node(value);
        tmp->next = head;
        head = tmp;
    }

    lsize++;
}

template<typename T>
void List<T>::PopBack()
{
    cout << "PopBack" << endl;
    if(head == nullptr) {
        cout << "PopBack: List is Empty!\n";
    } else {
        Node *tmp = head, *prev;

        while(tmp->next) {
            prev = tmp;
            tmp = tmp->next;
        }

        prev->next = nullptr;
        delete(tmp);
        tmp = nullptr;

        lsize--;
    }
}

template<typename T>
void List<T>::PopFront()
{
    cout << "PopFront" << endl;
    if(head == nullptr) {
        cout << "PopFront: List is Empty!\n";
    } else {
        Node* tmp = head;
        head = head->next;

        delete tmp;
        tmp = nullptr;

        lsize--;
    }
}

template<typename T>
void List<T>::Remove(const T& value)
{
    cout << "Deleting the node in list\n";
    if(head == nullptr) {
        cout << "Remove: List is Empty!\n";
    } else if(head->data == value)
    {
        Node* tmp = head;

        head = head->next;
        delete tmp;
        tmp = nullptr;
        lsize--;
    }
    else {
        Node *tmp = head->next, *prev = head;

        while(tmp) {
            if(tmp->data == value) {
                prev->next = tmp->next;
                delete tmp;
                tmp = nullptr;
                break;
            }

            prev = tmp;
            tmp = tmp->next;
        }

        lsize--;
    }
}

template<typename T>
typename List<T>::Node* List<T>::FindNode(const T& value)
{
    cout << "Finding the node in list\n";
    if(head == nullptr) {
        cout << "FindNode: List is Empty!\n";
    } else if(head->data == value)
    {
        return head;
    }
    else {
        Node *tmp = head->next;
        while(tmp) {
            if(tmp->data == value) {
                return tmp;
            }

            tmp = tmp->next;
        }
    }

    return nullptr;
}

template<typename T>
void List<T>::Clear()
{
    cout << "Deleting the list\n";
    if(head == nullptr) {
        cout << "List is empty!\n";
    } else {
        Node* prev = head;
        Node* tmp = head->next;

        while(tmp) {
            delete prev;
            prev = tmp;
            tmp = tmp->next;
        }

        head = nullptr;
        lsize = 0;
    }
}

template<typename T>
void List<T>::Reverse()
{
    cout << "Reversing the list\n";
    Node* prev, *next, *cur;

    prev = nullptr;
    cur = head;

    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;
}

template<typename T>
typename List<T>::Node* List<T>::FindMiddle()
{
    cout << "Finding the middle node in list\n";

    Node *fast = head, *slow = head;

    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

template<typename T>
bool List<T>::HasLoop() {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;           // 1 step
        fast = fast->next->next;     // 2 steps

        if (slow == fast) {
            cout << "Loop detected!\n";
            return true;
        }
    }

    cout << "No loop detected.\n";
    return false;
}

template<typename T>
typename List<T>::Node* List<T>::FindNthFromEnd(int n) {
    if (!head || n <= 0) return nullptr;

    Node* fast = head;
    Node* slow = head;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++) {
        if (!fast) return nullptr;  // n > length of list
        fast = fast->next;
    }

    // Move both until fast reaches end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow; // slow is at nth node from end
}

template<typename T>
void List<T>::PrintList()
{
    cout << "Printing the list" << endl;
    if(head == nullptr) {
        cout << "List is empty!\n";
    } else {
        Node *tmp = head;
        while(tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }

        cout << endl;
    }
}

int main()
{
    List<int> lobj;

    lobj.PrintList();

    return 0;
}
