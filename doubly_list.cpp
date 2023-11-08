#include <iostream>
using namespace std;
class linkedlist
{
public:
	linkedlist *prv;
	int data;
	linkedlist *next;
};

linkedlist *head = NULL;

void being_insertion()
{
	linkedlist *New = (linkedlist *)malloc(sizeof(linkedlist));
	int data;
	cout << "Enter The Data: ";
	cin >> data;
	New->data = data;
	New->next = head;
	if (head != NULL)
		head->prv = New;
	New->prv = NULL;
	head = New;
	cout << "element add successfully...\n";
}
void last_insertion()
{
	if(head == NULL)
	{
		being_insertion();
		return;
	}
	linkedlist *New = (linkedlist *)malloc(sizeof(linkedlist));
	int data;
	cout << "Enter The Data: ";
	cin >> data;
	linkedlist *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	New->data = data;
	New->next = temp->next;
	temp->next = New;
	New->prv = temp;
	cout << "element add successfully...\n";
}
void between_insertion()
{
	if (head == NULL || head->next == NULL)
	{
		cout << "List is empty...\n";
		return;
	}
	linkedlist *New = (linkedlist *)malloc(sizeof(linkedlist));
	int data, index, count = 0;
	cout << "Enter The Index: ";
	cin >> index;
	cout << "Enter The Data: ";
	cin >> data;
	linkedlist *temp = head;
	while (count != index - 1)
	{
		temp = temp->next;
		count++;
	}
	New->data = data;
	New->next = temp->next;
	temp->next->prv = New;
	temp->next = New;
	New->prv = temp;
	cout << "element add successfully...\n";
}
void being_del()
{
	if(head == NULL)
	{
		cout<<"List is empty...\n";
		return;
	}
	linkedlist *del = head;
	head = head->next;
	if(head != NULL)
		head->prv = NULL;
	free(del);
	cout<<"element delete successfully...\n";
}
void last_del()
{
	if(head == NULL)
	{
		cout<<"List is empty...\n";
		return;
	}
	else if(head->next == NULL)
	{
		being_del();
		return;
	}
	linkedlist *temp = head;
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	linkedlist *del = temp->next;
	temp->next = del->next;
	free(del);
	cout<<"element delete successfully...\n";
}
void between_del()
{
	if(head == NULL)
	{
		cout<<"list is empty...\n";
		return;
	}
	int index;
	cout<<"enter The index: ";
	cin>>index;
	if(index == 0)
	{
		being_del();
		return;
	}
	int count = 0;
	linkedlist *temp = head;
	while(count != index && temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	if(temp == NULL)
	{
		cout<<"Index not found...\n";
		return;
	}
	else if(temp->next == NULL)
	{
		last_del();
		return;
	}
	temp->prv->next = temp->next;
	temp->next->prv = temp->prv;
	free(temp);
	cout<<"element delete successfully...\n";
}
void display()
{
	linkedlist *temp = head;
	if(temp == NULL)
	{
		cout<<"List is empty...\n";
		return;
	}
	cout << "\nDisplay...\n\n";
	while (temp->next != NULL)
	{
		cout << "Element: " << temp->data << "\n";
		temp = temp->next;
	}
	cout << "Element: " << temp->data << "\n";
	// cout << "\nRev...\n\n";
	// do
	// {
	// 	cout << "Element: " << temp->data << "\n";
	// 	temp = temp->prv;
	// } while (temp != NULL);
}
void list_rev()
{
    linkedlist *last = NULL;
    while(last != head)
    {
    	linkedlist *temp = head;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        cout<<"data: "<<temp->data<<"\n";
        last = temp;
    }
}
int main()
{
	while(1)
	{
		int ch;
		cout<<"Enter The choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:being_insertion();break;
			case 2:last_insertion();break;
			case 3:between_insertion();break;
			case 4:being_del();break;
			case 5:last_del();break;
			case 6:between_del();break;
			case 7:display();break;
			case 8:exit(0);break;
			case 9:list_rev();break;
		}
	}
	return 0;
}