#include<iostream>
using namespace std;

void bubble_sort(int a[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-1;j++)
        {
            if (a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main() {
    int n;
    int a[10];
    cout<<"Enter the size of the array:";
    cin>>n;

    cout<<"Enter"<<n<<"integers in any order:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubble_sort(a,n);
    cout<<"Sorted array:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"";
    }
    cout<<endl;
    return 0;
}

OUTPUT 
PS D:\TejaswiniKolhe> cd "d:\TejaswiniKolhe\" ; if ($?) { g++ Bubble_sort.cpp -o Bubble_sort } ; if ($?) { .\Bubble_sort }
Enter the size of the array:5
Enter5integers in any order:
50 40 30 20 10 
Sorted array:1020304050
PS D:\TejaswiniKolhe> 
