#include <iostream>
using namespace std;
void display(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << "\n";
}
int part(int A[],int low,int high)
{
	int pivot = A[low];
	int i = low + 1;
	int j = high;
	do
	{
		while(i<high && !(A[i]>pivot))
		{
			i++;
		}
		while(j>0 && !(A[j]<=pivot))
		{
			j--;
		}
		if(j>i)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	while(j>i);
	int temp = A[low];
	A[low] = A[j];
	A[j] = temp;
	return j;
}
void quick_sort(int A[],int low,int high)
{
	if(low<high)
	{
		int pivot = part(A,low,high);
		quick_sort(A,pivot + 1,high);
		quick_sort(A,low,pivot-1);
	}
}
int main()
{
	int A[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7};
	int size = sizeof(A) / sizeof(int);
	display(A, size);
	quick_sort(A, 0, size - 1);
	display(A, size);
	return 0;
}