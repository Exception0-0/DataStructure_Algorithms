#include<iostream>
using namespace std;
int top = -1;
void push(int array[],int size)
{
	if(top == size-1)
	{
		cout<<"\nStack is overflow..."<<"\n\n";
	}
	else
	{
		int n;
		cout<<"Enter The Push Element: ";
		cin>>n;
		top++;
		array[top] = n;
		cout<<"\nelement push in stack....\n\n";   
	}
}
int pop(int array[])
{
	if(top == -1)
	{
		cout<<"\nstack is underflow..."<<"\n\n";
		return -1;
	}
	int temp = array[top];
	top--;
	return temp;
}
void display(int array[])
{
	if(top == -1)
	{
		cout<<"\nstack is underflow..."<<"\n\n";
	}
	else
	{
		cout<<"\nDisplay....\n";
		for(int i=top;i>=0;i--)
		{
			cout<<array[i]<<"\n";
		}
		cout<<"\n";
	}
}
int main()
{
	int array[5];
	int size = sizeof(array)/4;
	while(true)
	{
		cout<<"1.PUSH\t2.POP\t3.Display\n";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:push(array,size);break;
			case 2:pop(array);break;
			case 3:display(array);break;
		}
	}
	return 0;
}