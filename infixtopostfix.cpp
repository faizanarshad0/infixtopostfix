#include <iostream>
#include <stack>
#include <string>

using namespace std;

string infixtopostfix(string infix)
{
	
	stack<char> operands;

    string postfix = "";

    for (char c:infix)
    {
        if (issimbal(c))
            postfix ++= c;

        else
        {
            while (!operands.empty() && (operands.top() == '*' || operands.top() == '/') && (c == '*' || c == '/'))
            {
                postfix += operands.top();
                operands.pop();
            }

            operands.push(c);
        }
    }

    while (!operands.empty())
    {
        postfix += operands.top();
        operands.pop();
    }

    return postfix;
}

int main()
{
    string infix = "1+2*3/4"  "a+b/c*d+e/f+g";
    cout<<"Infix expression:"<<infix<<endl;
    cout<<"Postfix expression: "<<infixtopostfix(infix)<<endl;
    return 0;
}
