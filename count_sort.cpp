#include<bits/stdc++.h>
using namespace std;
void count_sort(int A[],int n)
{
	int max = 0;
	for(int i=0;i<n;i++)
	{
		if(max<A[i])
			max = A[i];
	}
	int *count = new int[max + 1];
	memset(count,0,max + 1);
	// int *count = (int*)calloc(max+ 1, (max+1)*sizeof(int));
	for(int i=0;i<n;i++)
	{
		count[A[i]]++;
	}
	int k = 0,i = 0;
	while(i<max + 1)
	{
		if(count[i]>0)
		{
			A[k] = i;
			count[i]--;
			k++;
		}
		else
		{
			i++;
		}
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
	int A[] = {3,1,4,56,12,40};
	int size = sizeof(A)/sizeof(int);
	count_sort(A,size);
	display(A,size);
	return 0;
}