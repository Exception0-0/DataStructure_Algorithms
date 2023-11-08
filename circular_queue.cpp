#include <iostream>
using namespace std;
class queue
{
public:
	int size, front, rear, *arr;
};

queue *head = new queue[sizeof(queue)];

bool isfull()
{
	if((head->rear + 1)%head->size == head->front)
		return true;
	return false;
}
bool isempty()
{
	if(head->rear == head->front)
		return true;
	return false;
}
void enqueue()
{
	if (isfull())
	{
		cout << "queue is full...\n";
		return;
	}
	head->rear = (head->rear + 1) % head->size;
	cout << "enter data: ";
	cin >> head->arr[head->rear];
	cout << "Element Add Successfully...\n";
}
int dequeue()
{
	if (isempty())
	{
		cout << "Queue is Empty...\n";
		return -1;
	}
	head->front = (head->front + 1) % head->size;
	cout << "element delete successfully...\n";
	return head->arr[head->front];
}
int peek()
{
	if(isempty())
	{
		cout<<"Queue is Empty...\n";
		return -1;
	}
	cout<<"Enter the index: ";
	int index;cin>>index;
	if(index + 1 >= head->size)
	{
		cout<<"invalid index...\n";
		return -1;
	}
	return head->arr[index + 1];
}
void display()
{
	if (head->rear == head->front)
	{
		cout << "Queue is Empty...\n";
		return;
	}
	int i = head->front;
	cout<<"\n\ndisplay...\n\n";
	while(i != head->rear)
	{
		i = (i + 1) % head->size;
		cout<<"Data: "<<head->arr[i]<<"\n";
	}
	cout<<"\n\n";
}
int main()
{
	head->size = 5;
	head->front = head->rear = 0;
	head->arr = new int[head->size];
	while(1)
	{
		cout<<"enter tha choice: ";
		int ch;cin>>ch;
		switch(ch)
		{
			case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			case 4:cout<<"element: "<<peek()<<"\n";break;
			case 5:exit(0);break;
		}
	}
	return 0;
}