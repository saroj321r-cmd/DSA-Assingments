#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// Print Doubly Linked List
void print(Node* head)
{
    Node* temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Insert at Front
void insertFront(Node*& head, int x)
{
    Node* node = new Node(x);

    node->next = head;

    if (head)
        head->prev = node;

    head = node;
}

// Insert at End
void insertEnd(Node*& head, int x)
{
    Node* node = new Node(x);

    if (head == NULL)
    {
        head = node;
        return;
    }

    Node* temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;
}

// Reverse Doubly Linked List
Node* reverseDLL(Node* head)
{
    Node* curr = head;
    Node* temp = NULL;

    while (curr)
    {
        temp = curr->prev;

        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    if (temp)
        head = temp->prev;

    return head;
}

// Delete Given Node
void deleteNode(Node*& head, Node* node)
{
    if (node == NULL)
        return;

    // If deleting head
    if (node == head)
    {
        head = head->next;

        if (head)
            head->prev = NULL;
    }
    else
    {
        if (node->prev)
            node->prev->next = node->next;

        if (node->next)
            node->next->prev = node->prev;
    }

    delete node;
}

// Print Circular Linked List
void printCircular(Node* head)
{
    if (head == NULL)
        return;

    Node* temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp != head);

    cout << endl;
}

int main()
{
    Node* head = NULL;

    // Insert at Front
    insertFront(head, 10);
    insertFront(head, 20);
    insertFront(head, 30);

    // Insert at End
    insertEnd(head, 40);
    insertEnd(head, 50);

    cout << "Original DLL: ";
    print(head);

    // Reverse DLL
    head = reverseDLL(head);

    cout << "After Reverse: ";
    print(head);

    // Delete node with value 20
    deleteNode(head, head->next->next->next);

    cout << "After Deletion: ";
    print(head);

    return 0;
}