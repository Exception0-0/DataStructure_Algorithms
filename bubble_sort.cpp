#include<iostream>
using std::cout;
using std::cin;
void bsort(int *a,int n)
{
    bool flag = false;
    for(int i=0;i<n && !flag;i++)
    {
        flag = true;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = false;
            }
        }
    }
}
void scan(int *a,int n)
{
    cout<<"enter data: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
}
void display(int *a,int n)
{
    cout<<"\n\ndisplay...\n";
    for(int i=0;i<n;i++)
    {
        cout<<"element: "<<a[i]<<"\n"; 
    }
    cout<<"\n";
}
int main()
{
    int size = 5;
    int *arr = new int[size];
    scan(arr,size);
    display(arr,size);
    bsort(arr,size);
    display(arr,size);
    return 0;
}