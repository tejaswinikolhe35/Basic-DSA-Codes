#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

class stack {
private:
    node *top;

public:
    stack() {
        top = NULL;
    }

    int empty() {
        if (top == NULL) {
            return 1;
        } else {
            return 0;
        }
    }

    void push(int x) {
        node *p = new node(x);
        p->next = top;
        top = p;
    }

    int pop(void) {
        int x = top->data;
        node *p = top;
        top = top->next;
        delete p;
        return x;
    }

    int peek() {
        return top->data;
    }

    void display() {
        node *q = top;
        while (q != NULL) {
            cout << endl << q->data;
            q = q->next;
        }
    }
};

int main() {
    int x;
    stack s;

    s.push(260);
    s.push(550);
    s.push(110);
    s.push(207);
    s.push(335);
    s.push(749);
    
    s.display();

    if (!s.empty()) {
        x = s.pop();
        cout << endl << "Removed" << x;
    }
    
    s.display();

    x = s.peek();
    cout << endl << "Top Element is:" << x;

    return 0;
}

OUTPUT:
PS D:\TejaswiniKolhe> cd "d:\TejaswiniKolhe\" ; if ($?) { g++ stack_linklist.cpp -o stack_linklist } ; if ($?) { .\stack_linklist }

749
335
207
110
550
260
Removed749
335
207
110
550
260
Top Element is:335
PS D:\TejaswiniKolhe> 


