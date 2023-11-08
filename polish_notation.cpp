#include<bits/stdc++.h>
using namespace std;
bool isOperator(string &S)
{
    if(S == "+" || S == "-" || S == "*" || S == "/")
        return true;
    return false;
}
string evalution(string &op1,string &op2,string &Operator)
{
    int a = stoi(op1),b = stoi(op2),c = 0;
    switch(Operator[0])
    {
        case '+' : c = a + b;break;
        case '-': c = a - b;break;
        case '*': c = a * b;break;
        case '/': c = a / b;break;
    }
    return to_string(c);
}
int evalRPN(vector<string>& tokens) 
{
    stack<string> st;
    for(int i=0;i<tokens.size();i++)
    {
        if(!isOperator(tokens[i]))
            st.push(tokens[i]);
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push(evalution(op1,op2,tokens[i]));
        }
    }
    return stoi(st.top());
}
int main()
{
    vector<string> V = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<evalRPN(V)<<"\n";
    return 0;
}