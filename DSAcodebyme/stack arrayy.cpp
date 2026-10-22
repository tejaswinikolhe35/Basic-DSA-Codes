#include<iostream>
using namespace std;

const int MAX = 5;

class Stack
{
    private:
    int a[MAX];
    int top;

    public:
    Stack()
    {
        top = -1;
    }
    void push(int x)
{
    top++;
    a[top]=x;
}
int pop(void)
{
    int x = a[top];
    top--;
    return x;
}
int peek(void)
{
    return a[top];
}
int full(void)
{
    if (top== MAX -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int empty(void)
{
    if (top== -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(void)
{
    for(int i=top;i>=0;i--)
    {
        cout<<endl<<a[i];
    }
}
};

int main()
{
    int x;
    Stack s;

    if(!s.full()) s.push(17);
    if(!s.full()) s.push(10);
    if(!s.full()) s.push(20);
    if(!s.full()) s.push(17);
    if(!s.full()) s.push(67);
    if(!s.full()) s.push(24);

    cout<<"Stack elements:";
    s.display();

    if (!s.empty())
    {
        x= s.pop();
        cout<<endl<<"Removed:"<<x;
    }
    cout<<endl<<"Stack after pop:";
    s.display();
    if(!s.empty())
    {
        x= s.peek();
        cout<<endl<<"Top element is:"<<x;
    }
    return 0;
}

OUTPUT:
PS D:\TejaswiniKolhe> cd "d:\TejaswiniKolhe\" ; if ($?) { g++ stack_array.cpp -o stack_array } ; if ($?) { .\stack_array }
Stack elements:
67
17
20
10
17
Removed:67
Stack after pop:
17
20
10
17
Top element is:17
PS D:\TejaswiniKolhe> 

