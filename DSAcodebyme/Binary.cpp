#include<iostream>
using namespace std;
int binary_search(int a[],int n,int x)
{
    int first = 0;
    int last = n-1;
    int mid;
    while (first<=last)
    {
        mid =(first+last)/2;
        if (a[mid]==x)
        {
            return mid;
        }

    else if (a[mid]<x)
    {
        first=mid+1;
    }
    else
    {
        last=mid-1;
    }
}
return-1;
}
int main()
{
    int n,x;
    int a[20];

    cout<<"Enter the size of the array:";
    cin>>n;

    cout<<"Enter" <<n<< "sorted integers:\n";
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the target element to search for:";
    cin>>x;
    int position = binary_search(a,n,x);
    if (position != -1)
    cout<<"Element found at position:"<<position<<endl;
    else
    cout<<"Element not found."<<endl;
    return 0;
}

OUTPUT 
PS D:\TejaswiniKolhe> cd "d:\TejaswiniKolhe\" ; if ($?) { g++ Binary.cpp -o Binary } ; if ($?) { .\Binary }
Enter the size of the array:5
Enter5sorted integers:
10 20 30 40 50
Enter the target element to search for:20
Element found at position:1
PS D:\TejaswiniKolhe> 

