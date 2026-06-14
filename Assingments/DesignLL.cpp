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

class MyLinkedList {
public:
    Node* head;

    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        Node* temp = head;
        int cnt = 0;

        while (temp) {
            if (cnt == index)
                return temp->data;

            temp = temp->next;
            cnt++;
        }

        return -1;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
    }

    void addAtTail(int val) {

        Node* node = new Node(val);

        if (head == NULL) {
            head = node;
            return;
        }

        Node* temp = head;

        while (temp->next) {
            temp = temp->next;
        }

        temp->next = node;
    }

    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        int cnt = 0;

        while (temp && cnt < index - 1) {
            temp = temp->next;
            cnt++;
        }

        if (temp == NULL)
            return;

        Node* node = new Node(val);

        node->next = temp->next;
        temp->next = node;
    }

    void deleteAtIndex(int index) {

        if (head == NULL)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        int cnt = 0;

        while (temp->next && cnt < index - 1) {
            temp = temp->next;
            cnt++;
        }

        if (temp->next == NULL)
            return;

        Node* del = temp->next;
        temp->next = del->next;

        delete del;
    }

    void print() {
        Node* temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    MyLinkedList list;

    list.addAtHead(1);
    cout << "After addAtHead(1): ";
    list.print();

    list.addAtTail(3);
    cout << "After addAtTail(3): ";
    list.print();

    list.addAtIndex(1, 2);
    cout << "After addAtIndex(1,2): ";
    list.print();

    cout << "get(1): " << list.get(1) << endl;

    list.deleteAtIndex(1);
    cout << "After deleteAtIndex(1): ";
    list.print();

    cout << "get(1): " << list.get(1) << endl;

    return 0;
}