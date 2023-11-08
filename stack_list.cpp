#include <iostream>
using namespace std;
class list
{
public:
    int data;
    list *prev;
};

list *top = NULL;

void push()
{
    int data;
    cout<<"Enter The Data: ";
    cin>>data;
    list *New = new list[sizeof(list)];
    New->data = data;
    New->prev = top;
    top = New;
    cout<<"element push successfully...\n";
}
void pop()
{
    if(top == NULL)
    {
        cout<<"stack is underflow...\n";
        return;
    }
    list *del = top;
    top = top->prev;
    delete del;
    cout<<"element pop successfully...\n";
}
void peek()
{
    if(top == NULL)
    {
        cout<<"stack is underflow...\n";
        return;
    }
    list *temp = top;
    int index,count = 0;
    cout<<"Enter The index: ";
    cin>>index;
    while(count != index && temp != NULL)
    {
        temp = temp->prev;
        count++;
    }
    if(temp == NULL)
    {
        cout<<"index not found...\n";
        return;
    }
    cout<<"Element: "<<temp->data<<"\n";
}
void display()
{
    if(top == NULL)
    {
        cout<<"stack is underflow...\n";
        return;
    }
    cout<<"\nDisplay....\n\n";
    list *temp = top;
    while(temp != NULL)
    {
        cout<<"Element: "<<temp->data<<"\n";
        temp = temp->prev;
    }
}
int main()
{
    while(1)
    {
        cout<<"Enter the choice: ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:peek();break;
            case 5:exit(0);break;
        }
    }
    return 0;
}