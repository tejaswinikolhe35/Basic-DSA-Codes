#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert node at the end
    void insert(int val) {
        Node* p = new Node(val); // p is used for new node
        if (head == nullptr) {
            head = p;
        } else {
            Node* q = head; // q is used for traversal
            while (q->next != nullptr) {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
        }
    }

    // Delete node by value
    void remove(int val) {
        Node *p,*q;
               q = head;

                if (q->data == val) {
                p = head;
                head=head->next;
                head->prev=nullptr;
                delete p;
                return;
                }
                
                while (q->next != NULL) {
            if (q->next->data == val) {
                p = q->next;
                q->next = p->next;
                p->next->prev=q;
                delete p;
                return;
            }
            q = q->next;
        }
       
  

        cout << "Value " << val << " not found in the list.\n";
    }

    // Display list forward
    void displayForward() {
        Node* q = head;
        cout << "Forward: ";
        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->next;
        }
        cout << "NULL\n";
    }

    // Display list backward
    void displayBackward() {
        Node* q = head;
        if (q == nullptr) {
            cout << "Backward: NULL\n";
            return;
        }

        // Move to the tail
        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "Backward: ";
        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->prev;
        }
        cout << "NULL\n";
    }
};

// Main function to test the doubly linked list
int main() {
    DoublyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.displayForward();   // Output: Forward: 10 <-> 20 <-> 30 <-> NULL
    list.displayBackward();  // Output: Backward: 30 <-> 20 <-> 10 <-> NULL

    list.remove(20);
    list.displayForward();   // Output: Forward: 10 <-> 30 <-> NULL
    list.displayBackward();  // Output: Backward: 30 <-> 10 <-> NULL

    return 0;
}

OUTPUT:
PS D:\TejaswiniKolhe> cd "d:\TejaswiniKolhe\" ; if ($?) { g++ doublylinklist.cpp -o doublylinklist } ; if ($?) { .\doublylinklist }
Forward: 10 <-> 20 <-> 30 <-> NULL
Backward: 30 <-> 20 <-> 10 <-> NULL
Forward: 10 <-> 30 <-> NULL
Backward: 30 <-> 10 <-> NULL
PS D:\TejaswiniKolhe> 
