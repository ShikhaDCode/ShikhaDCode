#include<iostream>

using namespace std;

typedef struct list{
    int data;
    struct list* next;
    list(){
        data = 0;
        next = nullptr;
    }
} Node;

void InsertAtBeg(Node*& head, int value)
{
    cout << "Debug1\n";
    if(head == nullptr){
        head = new Node;
        head->data = value;
        head->next = nullptr;
    } else {
        Node *newNode;
        Node *tmp = head;
        newNode = new Node;
        newNode->next = head;
        newNode->data = value;
    }

}

void PrintList(Node* head)
{
    cout << "Debug2\n";
    if(head == nullptr){
        cout << "List is empty!\n";
    } else{
        while(head != nullptr){
            cout << head->data << " -> ";
            head = head->next;
        }
        cout << endl;
    }
}

int main()
{
    Node* head = nullptr;

    (*head).data = 20;

    InsertAtBeg(head, 10);
    InsertAtBeg(head, 20);
    InsertAtBeg(head, 30);
    InsertAtBeg(head, 40);

    PrintList(head);
    return 0;
}