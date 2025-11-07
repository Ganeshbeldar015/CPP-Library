#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    for(char ch : infix) {
        if(isalnum(ch))
            postfix += ch;
        else if(ch == '(')
            st.push(ch);
        else if(ch == ')') {
            while(st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> st;
    for(char ch : postfix) {
        if(isdigit(ch))
            st.push(ch - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch(ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter Infix: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    cout << "Value: " << evaluatePostfix(postfix) << endl;
}
