#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    private:
    Node*head;

    public:
    LinkedList(){
        head = NULL;
    }
    void insert(int val){
        Node*p= new Node(val);
        if (head == NULL){
            head = p;
        }else{
            Node*q =head;
            while(q->next!= NULL){
                q = q->next;
            }
            q->next=p;
        }
    }
    void remove(int val){
        Node*p=NULL;
        Node*q=head;

        if (q!=NULL && q->data == val){
            p=head;
            head=head->next;
            delete p;
            return;
        }
        while(q->next!=NULL){
        if(q->next->data==val){
            p=q->next;
            q->next=p->next;
            delete p;
            return;
        }
        q=q->next;
    }

    cout<<endl<<"Value"<<val<<"not found in the list.\n";
}
 void display(){
    cout<<endl<<"Linked List";
    Node*q=head;
    while (q!=NULL){
        cout<<q->data<<"->";
        q = q->next;
    }
}
};

int main(){
LinkedList list;

list.insert(10);
list.insert(20);
list.insert(30);
list.display();

list.insert(40);
list.insert(50);
list.insert(60);
list.display();

list.remove(40);
list.display();

list.remove(60);
list.display();

list.remove(100);
list.display();

return 0;
}

OUTPUT:
PS D:\TejaswiniKolhe> cd "d:\TejaswiniKolhe\" ; if ($?) { g++ singlylinklist.cpp -o singlylinklist } ; if ($?) { .\singlylinklist }

Linked List10->20->30->
Linked List10->20->30->40->50->60->
Linked List10->20->30->50->60->
Linked List10->20->30->50->
Value100not found in the list.

Linked List10->20->30->50->
PS D:\TejaswiniKolhe> 
