#include<iostream>
using namespace std;
int front=0,rear=-1;
 void insertion(int arr[],int size)
{
    if(rear == size-1)
    {
        cout<<"queue is full...\n";
        return;
    }    
    cout<<"enter the data: ";
    cin>>arr[++rear];
    cout<<"element insert successsfully...\n";
}
void deletion(int arr[])
{
    if(rear == -1)
    {
        cout<<"Queue is empty...\n";
        return;
    }
    for(int i=1;i<rear;i++)
    {
        arr[i-1] = arr[i];
    }
    rear--;
    cout<<"Element delete successfully....\n";
}
void display(int arr[])
{
    if(rear == front)
    {
        cout<<"Queue is empty...\n";
        return;
    }
    cout<<"display.....\n";
    for(int i=0;i<rear;i++)
    {
        cout<<"Element:"<<arr[i]<<"\n";
    }
}
int main()
{
    int n;
    cout<<"enter the queue size: ";
    cin>>n;
    int arr[n];
    
    while(1)
    {
        int ch;
        cout<<"enter the choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:insertion(arr,n);break;
            case 2:deletion(arr);break;
            case 3:display(arr);break;
            case 4:exit(0);break;
        }
    }

    return 0;
}
