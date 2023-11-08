#include<iostream>
#include<stack>
using namespace std;
int precision(char c)
{
	if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string Postfix(string s)
{
	stack<char>sc;
	string result = "";
	for(int i=0;i<s.length();i++)
	{
		if('a'<= s[i] && s[i]<='z' || 'A'<= s[i] && s[i]<='Z' || '0'<= s[i] && '9' <= s[i])
		{
			result += s[i];
		}
		else if(s[i] == '(')
		{
			sc.push(s[i]);
		}
		else if(s[i] == ')')
		{
			while(sc.top() != '(')
			{
				result += sc.top();
				sc.pop(); 
			}
			sc.pop();
		}
		else
		{
			while(!sc.empty() && precision(s[i]) <= precision(sc.top()))
			{
				result += sc.top();
				sc.pop();
			}
			sc.push(s[i]);
		}
	}
	while(!sc.empty())
	{
		result += sc.top();
		sc.pop();
	}
	return result;
}
int main()
{
	string s;
	cin>>s;
	cout<<"PostFix: "<<Postfix(s)<<"\n";
	return 0;
}