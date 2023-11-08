#include<iostream>
using namespace std;
class linkedlist
{
public:
	int data;
	linkedlist *next;
};
linkedlist *head = NULL;
bool isfull()
{
	linkedlist *New = new linkedlist();
	if(New == NULL)
		return true;
	delete New;
	return false;
}
void add_being()
{
	linkedlist *New = new linkedlist();
	if(New == NULL)
	{
		cout<<"list is full...\n";
		return ;
	}
	cout<<"enter the data: ";
	cin>>New->data;
	New->next = head;
	head = New;
	cout<<"element add successfully...\n";
}
void add_last()
{
	linkedlist *New = new linkedlist();
	if(New == NULL)
	{
		cout<<"list is full...\n";
		return ;
	}
	cout<<"enter the data: ";
	cin>>New->data;
	linkedlist *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	New->next = temp->next;
	temp->next = New;
	cout<<"element add successfully...\n";
}
void add_between()
{
	linkedlist *New = new linkedlist();
	if(New == NULL)
	{
		cout<<"list is full...\n";
		return ;
	}
	int position,count = 0;
	cout<<"enter the position: ";
	cin>>position;
	linkedlist *temp = head;
	while(temp != NULL && count != position - 1)
	{
		temp = temp->next;
		count++;
	}
	if(temp == NULL)
	{
		cout<<"position is invalid...\n";
		delete New;
		return ;
	}
	cout<<"enter the data: ";
	cin>>New->data;
	New->next = temp->next;
	temp->next = New;
	cout<<"element add successfully...\n";
}
void reverse(linkedlist *head)
{
	if(head != NULL)
	{
		reverse(head->next);
		cout<<head->data<<" ";
	}
	// linkedlist *set = NULL;
	// linkedlist *ch = head;
	// while(ch != NULL)
	// {
	// 	ch = ch->next;
	// 	head->next = set;
	// 	set = head;
	// 	if(ch != NULL)
	// 	head = ch;
	// }
	// cout<<"list is set reversed...\n";
}
void duplicate()
{
	linkedlist *prev = head;
    linkedlist *Next = head->next;
    while(Next != NULL)
    {
        if(prev->data == Next->data)
        {
            prev->next = Next->next;
            delete Next;
            Next = prev->next;
        }
        else
        {
            prev = prev->next;
            Next = Next->next;
        }
   }
}
void display()
{
	linkedlist *temp = head;
	if(temp == NULL)
	{
		cout<<"list is empty...\n";
		return;
	}
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}
int main()
{
	while(1)
	{
		int ch;cin>>ch;
		switch(ch)
		{
			case 1:add_being();break;
			case 2:add_last();break;
			case 3:add_between();break;
			case 4:reverse(head);break;
			case 5:exit(0);
			case 6:display();break;
			case 7:duplicate();break;
		}
	}
	return 0;
}