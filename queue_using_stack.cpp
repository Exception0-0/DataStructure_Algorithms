#include<iostream>
using namespace std;
class stack
{
public:
	int Data;
	stack *ptr;
stack* push(int,stack*&);
int pop(stack*&);
void display(stack*);
bool isEmpty(stack*);
};

stack* stack::push(int data,stack *&Top)
{
	stack *New = new stack();
	New->Data = data;
	New->ptr = Top;
	Top = New;
	return Top;
}
int stack::pop(stack *&Top)
{
	stack *del = Top;
	Top = Top->ptr;
	int temp = del->Data;
	delete del;
	return temp;
}
void stack::display(stack *Top)
{
	if(Top == NULL)
	{
		cout<<"stack is Empty...\n";
		return;
	}
	stack *temp = Top;
	while(temp != NULL)
	{
		cout<<temp->Data<<" ";
		temp = temp->ptr;	
	}
	cout<<"\n";
}
bool stack::isEmpty(stack *Top)
{
	if(Top != NULL)
		return false;
	return true;
}
void enqueue(int data,stack *&Ftop)
{
	Ftop->push(data,Ftop);
	cout<<"element add successfully...\n";
}
int dequeue(stack *&Ftop,stack *&Stop)
{
	if(Ftop == NULL)
		return -1;
	while(!Ftop->isEmpty(Ftop))
	{
		int data = Ftop->pop(Ftop);
		Stop->push(data,Stop);
	}
	int del = Stop->pop(Stop);
	while(!Stop->isEmpty(Stop))
	{
		int data = Stop->pop(Stop);
		Ftop->push(data,Ftop);
	}
	return del;
}
void display(stack *Ftop,stack *Stop)
{
	while(!Ftop->isEmpty(Ftop))
	{
		int data = Ftop->pop(Ftop);
		Stop->push(data,Stop);
	}
	stack *Temp = Stop;
	while(Temp != NULL)
	{
		cout<<Temp->Data<<" ";
		Temp = Temp->ptr;
	}
	while(!Stop->isEmpty(Stop))
	{
		int data = Stop->pop(Stop);
		Stop->push(data,Ftop);
	}
	cout<<"\n";
}
int main()
{
	stack *Ftop = NULL;
	stack *Stop = NULL;
	while(1)
	{
		int ch;cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"Enter the data: ";
			int data;cin>>data;
			enqueue(data,Ftop);break;
			case 2:
			printf("Delete: %d\n",dequeue(Ftop,Stop));break;
			case 3:display(Ftop,Stop);break;
			case 4:exit(0);break;
		}
	}
	return 0;
}