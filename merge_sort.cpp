#include<iostream>
using namespace std;
void display(int A[],int n)
{
	cout<<"display...\n";
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<"\n";
}
void sort(int A[],int low,int mid,int high)
{
	int i = low;
	int j = mid+1;
	int k = low;
	int B[100];
	while(i<=mid && j<=high)
	{
		if(A[i]<A[j])
		{
			B[k] = A[i];
			k++;i++;
		}
		else
		{
			B[k] = A[j];
			j++;k++;
		}
	}
	while(i<=mid)
	{
		B[k] = A[i];
		k++;i++;
	}
	while(j<=high)
	{
		B[k] = A[j];
		j++;k++;
	}
	for(int i=low;i<=high;i++)
	{
		A[i] = B[i];
	}
}
void merge_sort(int A[],int low,int high)
{
	if(low<high)
	{
		int mid = (low + high)/2;
		merge_sort(A,low,mid);
		merge_sort(A,mid+1,high);
		sort(A,low,mid,high);
	}
}
int main()
{
	int A[] = {34 ,12, 23 ,90 ,7};
	merge_sort(A,0,4);
	display(A,5);	
	return 0;
}