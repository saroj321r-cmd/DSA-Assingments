#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node* child;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

Node* solve(Node* head) {

    Node* curr = head;
    Node* last = head;

    while (curr) {

        Node* nextNode = curr->next;

        if (curr->child) {

            Node* childHead = curr->child;
            Node* childTail = solve(childHead);

            curr->next = childHead;
            childHead->prev = curr;
            curr->child = NULL;

            if (nextNode) {
                childTail->next = nextNode;
                nextNode->prev = childTail;
            }

            last = childTail;
        }
        else {
            last = curr;
        }

        curr = nextNode;
    }

    return last;
}

Node* flatten(Node* head) {

    if (head == NULL)
        return NULL;

    solve(head);

    return head;
}

void print(Node* head) {

    while (head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // Main List: 1 <-> 2 <-> 3

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Child List: 4 <-> 5

    Node* four = new Node(4);
    Node* five = new Node(5);

    four->next = five;
    five->prev = four;

    // Attach child to node 2

    head->next->child = four;

    cout << "Original Flattened List: ";
    head = flatten(head);

    print(head);

    return 0;
}