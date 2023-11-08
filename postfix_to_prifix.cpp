#include<iostream>
#include<stack>
using namespace std;
bool isOperator(char Operator)
{
	switch(Operator)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		return true;
	}
	return false;
}
string prifix(string postfix)
{
	stack<string>s;
	for(int i=0;i<postfix.length();i++)
	{
		if(isOperator(postfix[i]))
		{
			string a = s.top();
			s.pop();
			string b = s.top();
			s.pop();
			string temp = postfix[i] + b + a;
			s.push(temp);
		}
		else
		{
			string temp = "";
			temp += postfix[i];
			s.push(temp);
		}
	}
	return s.top();
}
int main()
{
	string s;
	cin>>s;
	cout<<"prifix: "<<prifix(s)<<"\n";
	return 0;
}