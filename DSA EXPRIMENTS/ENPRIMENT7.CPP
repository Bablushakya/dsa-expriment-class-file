//  Write a program to evaluate a postfix expression using stacks. 
#include <iostream>
#include <stack>
using namespace std;

int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;  // For '('
}

string infixToPostfix(const string& infix) {
    stack<char> stk;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;  // Add operands to the postfix expression
        } else if (ch == '(') {
            stk.push(ch);
        } else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();  // Pop '('
        } else {
            while (!stk.empty() && getPrecedence(ch) <= getPrecedence(stk.top())) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }

    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}

int main() {
    string infixExpression = "a+b*(c^d-e)^(f+g*h)-i";
    string postfixExpression = infixToPostfix(infixExpression);
    
    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}
