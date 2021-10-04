#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
infix expression - a op b 
(operator between every pair of nodes)

postfix expression - a b op 
(operator if followed for every pair of operands)

to evaluate infix expression we need to scan it
multiple times if op are different,
it's inefficient - we can optimize it using stack
*/

// function to return the precedence of
// operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> stack;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // if scanned character is operand,
        // add it to the output string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            stack.push(c);
        else if (c == ')') {
            while (stack.top() != '(') {
                result += stack.top();
                stack.pop();
            }
            stack.pop(); // remove '(' as well
        }

        // if operator is scanned
        else {
            // while s[i] is equally important as rest of operators
            while (!stack.empty() && precedence(s[i]) <= precedence(stack.top())) {
                result += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    // pop all remainings elements
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }

    return result;
}

// works just for digits, for >9
// it can be updated (space seperated empty)
int evaluatePostfix(string S) {
    stack<int> stack;
    char current;
    int a, b;
    
    for (int i = 0; i < S.length(); i++) {
        current = S[i];
        
        if (isdigit(current))
            stack.push(current - '0');
        else {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            
            switch (current) {
                case '^': stack.push(pow(b, a)); break;
                case '*': stack.push(b * a); break;
                case '/': stack.push(b / a); break;
                case '+': stack.push(b + a); break;
                case '-': stack.push(b - a); break;
            }
        }
    }
    
    return stack.top();
}

int main() {
    string exp = "2^4*5"; //
    exp = infixToPostfix(exp);
    cout << exp << endl;
    int result = evaluatePostfix(exp);
    cout << result << endl;

    return 0;
}