#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class queue
{
    private:
    node*front;
    node*rear;

    public:
    queue()
    {
        front = rear = NULL;
    }
    int empty(void)
    {
        if (front == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int peek(void)
    {
        if (empty())
        {
            cout<<"\nQueue is empty";
            return -1;
        }
        return front->data;
    }
    void enqueue(int x)
    {
        node*p= new node(x);

        if (front == NULL)
            {
                front = p;
                rear = p;
            }
            else
            {
                rear->next = p;
                rear = p;
            }
    }
    int dequeue(void)
    {
        if (empty())
        {
            cout<<"\nQueue is empty";
            return -1;
        }
        int x = front->data;
        node*p= front;

        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }
        delete p;
        return x;
    }
    void display(void)
    {
        node*q=front;
        cout<<"\nQueue elements:";
        while(q != NULL)
        {
            cout<<"\t"<<q->data;
            q = q->next;
        }
    }
};

int main()
{
    int x;
    queue q;

    q.enqueue(27);
    q.enqueue(34);
    q.enqueue(42);
    q.enqueue(58);
    q.enqueue(65);
    q.enqueue(70);

    q.display();
    if (!q.empty())
    {
        x=q.dequeue();
        cout<<"\nRemoveed:"<<x;
    }
    q.display();
    cout<<"\nFront element is:"<<x;
    return 0;
}

OUTPUT:
PS D:\TejaswiniKolhe> cd "d:\TejaswiniKolhe\" ; if ($?) { g++ queue_linklist.cpp -o queue_linklist } ; if ($?) { .\queue_linklist }

Queue elements: 27      34      42      58      65      70
Removeed:27
Queue elements: 34      42      58      65      70
Front element is:27
PS D:\TejaswiniKolhe> 


