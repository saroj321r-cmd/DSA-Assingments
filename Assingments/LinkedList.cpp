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

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertFront(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int x) {
        Node* newNode = new Node(x);

        if(head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertPosition(int pos, int x) {
        if(pos == 1) {
            insertFront(x);
            return;
        }

        Node* newNode = new Node(x);
        Node* temp = head;

        for(int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if(temp == NULL) return;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFront() {
        if(head == NULL) return;

        Node* temp = head;
        head = head->next;

        delete temp;
    }

    void deleteLast() {
        if(head == NULL) return;

        if(head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while(temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deletePosition(int pos) {
        if(head == NULL) return;

        if(pos == 1) {
            deleteFront();
            return;
        }

        Node* temp = head;

        for(int i = 1; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }

        if(temp->next == NULL) return;

        Node* del = temp->next;
        temp->next = del->next;

        delete del;
    }

    bool search(int key) {
        Node* temp = head;

        while(temp != NULL) {
            if(temp->data == key)
                return true;

            temp = temp->next;
        }

        return false;
    }

    int length() {
        int count = 0;
        Node* temp = head;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    int maximum() {
        if(head == NULL)
            return -1;

        int mx = head->data;
        Node* temp = head;

        while(temp != NULL) {
            if(temp->data > mx)
                mx = temp->data;

            temp = temp->next;
        }

        return mx;
    }

    int sum() {
        int total = 0;
        Node* temp = head;

        while(temp != NULL) {
            total += temp->data;
            temp = temp->next;
        }

        return total;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void display() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main() {
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    list.insertFront(5);
    
    list.insertPosition(4, 25);

    cout << "Linked List: ";
    list.display();

    cout << "Length = " << list.length() << endl;
    
    cout << "Maximum = " << list.maximum() << endl;
    
    cout << "Sum = " << list.sum() << endl;

    if(list.search(10))
        cout << " Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Reversed List: ";
    list.reverse();
    
    list.isEmpty();

    return 0;
}