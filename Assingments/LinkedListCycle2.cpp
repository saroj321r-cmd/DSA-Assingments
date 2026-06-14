#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* detectCycle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {

        slow = slow->next;
        fast = fast->next->next;
      
        if (slow == fast) {
            slow = head;

            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
    return NULL;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating cycle:
    // 5 -> 2

    head->next->next->next->next->next = head->next;

    Node* ans = detectCycle(head);

    if (ans)
        cout << "Cycle starts at node: " << ans->data << endl;
    else
        cout << "No Cycle Found" << endl;

    return 0;
}