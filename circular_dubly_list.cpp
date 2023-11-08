#include<iostream>
using namespace std;
class list
{
public:
	list *prev;
	int data;
	list *next;
};
list *last = NULL;

void add_being()
{
	list *New = new list();
	if(New == NULL)
	{
		cout<<"list is full...\n";
		return;
	}
	cout<<"enter the data: ";
	cin>>New->data;
	if(last != NULL)
	{
		if(last->next != last)
		{
			list *temp = last->next;
			temp->prev = New;
			New->next = temp;
			New->prev = last;
			last->next = New;
		}
		else
		{
			last->prev = New;
			last->next = New;
			New->next = last;
			New->prev = last;
		}
	}
	else
	{
		last = New;
		New->next = last;
		New->prev = last;
	}
	cout<<"element add successfully...\n";
}
void add_last()
{
	list *New = new list();
	if(New == NULL)
	{
		cout<<"list is full...\n";
		return;
	}
	cout<<"enter the data: ";
	cin>>New->data;
	if(last == NULL)
	{
		last = New;
		New->next = last;
		New->prev = last;
	}
	else
	{
		if(last->next != last)
		{
			New->next = last->next;
			last->next = New;
			New->prev = last;
			New->next->prev = New;
		}
		else
		{
			last->next = New;
			last->prev = New;
			New->next = last;
			New->prev = last;
		}
	}
	last = New;
	cout<<"element add successfully...\n";
}
void display()
{
	if(last == NULL)
	{
		cout<<"list is empty...\n";
		return;
	}
	list *temp = last->next;
	cout<<"In Order...\n";
	do
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	while(temp != last->next);
	cout<<"\nIn reverse Order...\n";
	do
	{
		cout<<temp->data<<" ";
		temp = temp->prev;
	} 
	while (temp != last->next);
	cout<<"\n";
}
int main()
{
	add_being();
	add_being();
	add_being();
	add_last();
	add_last();
	add_last();
	display();
	return 0;
}