#include<iostream>
#include<string.h>
using namespace std;
class list
{
public:
    int data;
    list *prev;
};

list *top = NULL;

void push(int data)
{
    list *New = new list();
    New->data = data;
    New->prev = top;
    top = New;
}
int pop()
{
    list *del = top;
    top = top->prev;
	int temp = del->data;
    delete del;
	return temp;
}
int cal(int A,int B,char op)
{
	switch(op)
	{
		case '+':return A + B;break;
		case '-':return A - B;break;
		case '*':return A * B;break;
		case '/':return A / B;break;
		case '%':return A % B;break;
	}
	return -1;
}
int eval(char* A,int n)
{
	for(int i=0;i<n;i++)
	{
		if(A[i]=='+' || A[i] == '-' || A[i] == '*' || A[i] == '/' || A[i] == '%')
		{
			int op2 = pop();
			int op1 = pop();
			int result = cal(op1,op2,A[i]);
			push(result);
		}
		else 
		{
			push((A[i] - '0'));
		}
	}
	return top->data;
}
int main()
{
	char A[100];
	cout<<"enter: ";
	cin>>A;
	cout<<"result: "<<eval(A,strlen(A))<<"\n";
	return 0;
}