#include <iostream>
using namespace std;
class list
{
public:
	int data;
	list *next;
};
list *last = NULL;
void first_insertion()
{
	// cout << "first_insertion...\n";
	list *New = new list[sizeof(list)];
	cout << "Enter The data: ";
	cin >> New->data;
	New->next = New;
	last = New;
	cout<<"insertion successful...\n";
}
void being_insertion()
{
	if (last == NULL)
	{
		first_insertion();
		return;
	}
	// cout << "being_insertion...\n";
	list *New = new list[sizeof(list)];
	cout << "Enter the data: ";
	cin >> New->data;
	New->next = last->next;
	last->next = New;
	cout<<"insertion successful...\n";
}
void last_insertion()
{
	if (last == NULL)
	{
		first_insertion();
		return;
	}
	// cout << "last_insertion...\n";
	list *New = new list[sizeof(list)];
	cout << "Enter The data: ";
	cin >> New->data;
	list *temp = last->next;
	last->next = New;
	New->next = temp;
	last = New;
	cout<<"insertion successful...\n";
}
void between_insertion()
{
	int index,count = 0;
	cout<<"Enter The index:";
	cin>>index;
	if(last == NULL || index == 0)
	{
		first_insertion();
		return;
	}
	list *New = new list[sizeof(list)];
	cout<<"Enter the Data: ";
	cin>>New->data;
	list *temp = last->next;
	while(count != index-1)
	{
		temp = temp->next;
		count++;
	}
	New->next = temp->next;
	temp->next = New;
	cout<<"insertion successful...\n";
}
void being_del()
{
	if(last == NULL)
	{
		cout<<"list is empty...\n";
		return;
	}
	list *del = last->next;

	if(last->next != del->next)
		last->next = del->next;
	else
		last = NULL;

	free(del);
	cout<<"deletion successful...\n";
}
void last_del()
{
	if(last == NULL)
	{
		cout<<"list is empty...\n";
		return;
	}
	list *temp = last->next;
	if(temp == last)
	{
		list *del = temp;
		last = NULL;
		free(del);
		return;
	}
	while(temp->next != last)
	{
		temp = temp->next;
	}
	list *del = temp->next;
	temp->next = last->next;
	last = temp;
	free(del);
	cout<<"deletion successful...\n";
}
void between_del()
{
	if(last == NULL)
	{
		cout<<"list is empty...\n";
		return;
	}
	int index,count = 0;
	cout<<"enter the index: ";
	cin>>index;
	if(index == 0)
	{
		being_del();
		return;
	}
	list *temp = last->next;
	while(count != index-1)
	{
		temp = temp->next;
		count++;
	}
	list *del = temp->next;
	temp->next = del->next;
	cout<<"deletion successful...\n";
}
void reverse()
{
	list *set = last;
	last = last->next;
	list *ch = last;
	while(last->next != set)
	{
		last = last->next;
		ch->next = set;
		set = ch;
		ch = last;
	};
	cout<<"list is reversed...\n";
}
void display()
{
	if(last == NULL)
	{
		cout<<"list is empty...\n";
		return;
	}
	list *temp = last->next;
	cout << "\n\nDisplay...\n";
	do
	{
		cout << "element: " << temp->data << "\n";
		temp = temp->next;
	} while (temp != last->next);
}
int main()
{
	while(1)
	{
		cout<<"enter the choice: ";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:being_insertion();break;
			case 2:last_insertion();break;
			case 3:between_insertion();break;
			case 4:being_del();break;
			case 5:last_del();break;
			case 6:between_del();break;
			case 7:reverse();break;
			case 8:display();break;
			case 9:exit(0);break;
		}
	}
	return 0;
}