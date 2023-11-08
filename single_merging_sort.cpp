#include<iostream>
using namespace std;
void scan(int A[],int n)
{
	cout<<"enter the element: ";
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
}
void merge_sort(int A[],int low,int high)
{
    int B[high + 1];
    int mid = (low + high)/2;
    int i = low;
    int j = mid + 1;
    int k = 0;
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for(int i=0;i<=high;i++)
    {
        A[i] = B[i];
    }
}
void display(int A[],int n)
{
	cout<<"display...\n";
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<"\n";
}
int main()
{
    int N;
    cout<<"enter the size: ";
    cin>>N;
    int A[N];
    scan(A,N);
    merge_sort(A,0,N-1);
    display(A,N);
    return 0;
}