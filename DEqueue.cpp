#include<iostream>
using std::cout;
using std::cin;
class DEqueue
{
public:
	int size,front,rear,*arr;
};

DEqueue E;
void rear_enqueue()
{
	if(E.rear == E.size-1)
	{
		cout<<"DEque is full...\n";
		return;
	}
	cout<<"enter data: ";
	cin>>E.arr[++E.rear];
	cout<<"element add at rear successfully...\n";
}
int front_dequeue()
{
	if(E.front == E.rear)
	{
		cout<<"DEque is Empty...\n";
		return -1;
	}
	int temp = E.arr[++E.front];
	cout<<"element delete at front successfully...\n";
	return temp;
}
void front_enqueue()
{
	if(E.front == -1)
	{
		cout<<"DEque is Full...\n";
		return;
	}
	cout<<"enter data: ";
	cin>>E.arr[E.front--];
	cout<<"element add at front successfully...\n";
}
int rear_dequeue()
{
	if(E.rear == E.front)
	{
		cout<<"DEqueue is Empty...\n";
		return -1;
	}
	int temp = E.arr[--E.rear];
	cout<<"element delete at front successfully...\n";
	return temp;
}
void display()
{
	if(E.rear == E.front)
	{
		cout<<"DEqueue is Empty...\n";
		return;
	}
	cout<<"\n\nDisplay...\n";
	for(int i=E.front+1;i<=E.rear;i++)
	{
		cout<<"data: "<<E.arr[i]<<"\n";
	}
	cout<<"\n";
}
int main()
{
	E.size = 5;
	E.front = E.rear = -1;
	E.arr = new int[E.size];
	while(1)
	{
		int ch;
		cout<<"enter the choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:rear_enqueue();break;
			case 2:front_dequeue();break;
			case 3:rear_dequeue();break;
			case 4:front_enqueue();break;
			case 5:display();break;
			case 6:exit(0);
		}
	}
	return 0;
}