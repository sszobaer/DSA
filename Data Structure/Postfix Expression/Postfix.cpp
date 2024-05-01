#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c) {
    return isdigit(c);
}

int evaluatePostfixExpression(const string &postfix) {
    stack<int> operandStack;

    for (char c : postfix) {
        if (isOperand(c)) {
            operandStack.push(c - '0');
        } else {

            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (c) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                case '^':
                    operandStack.push(operand1^operand2);
                    break;
            }
        }
    }


    return operandStack.top();
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    int result = evaluatePostfixExpression(postfixExpression);
    cout << "The result of this postfix expreesion: " << result << endl;

    return 0;
}
