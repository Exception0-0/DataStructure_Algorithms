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
void merge_sort(int A[],int B[],int C[],int n,int m)
{
	int i,j,k;
	i = j = k = 0;
	while(i<n && j<m)
	{
		if(A[i]<B[j])
		{
			C[k] = A[i];
			i++;
			k++;
		}
		else
		{
			C[k] = B[j];
			j++;
			k++;
		}
	}
	while(i<n)
	{
		C[k] = A[i];
		i++;
		k++;
	}
	while(j<m)
	{
		C[k] = B[j];
		j++;
		k++;
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
	int n,m;
	cout<<"enter the FIRST Array size: ";
	cin>>n;
	int A[n];
	scan(A,n);
	cout<<"enter the SECOND Array size: ";
	cin>>m;
	int B[m];
	scan(B,m);
	int C[n + m];
	merge_sort(A,B,C,n,m);
	display(C,(n+m));
	return 0;
}