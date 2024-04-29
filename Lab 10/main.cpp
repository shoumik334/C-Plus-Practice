#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "stacktype.cpp"

using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stringstream postfix;
    StackType<char> opStack;

    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix << ch << ' ';
        } else if (ch == '(') {
            opStack.Push(ch);
        } else if (ch == ')') {
            while (!opStack.IsEmpty() && opStack.Top() != '(') {
                postfix << opStack.Top() << ' ';
                opStack.Pop();
            }
            if (!opStack.IsEmpty() && opStack.Top() == '(')
                opStack.Pop(); // Discard the '('
        } else if (isOperator(ch)) {
            while (!opStack.IsEmpty() && precedence(opStack.Top()) >= precedence(ch)) {
                postfix << opStack.Top() << ' ';
                opStack.Pop();
            }
            opStack.Push(ch);
        }
    }

    while (!opStack.IsEmpty()) {
        postfix << opStack.Top() << ' ';
        opStack.Pop();
    }

    return postfix.str();
}

// Function to evaluate postfix expression
// Function to evaluate postfix expression
double evaluatePostfix(const string& postfix) {
    StackType<double> operandStack;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            operandStack.Push(stod(token));
        } else if (isOperator(token[0])) {
            double operand2 = operandStack.Top();
            operandStack.Pop();
            double operand1 = operandStack.Top();
            operandStack.Pop();

            double result;
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0)
                        result = operand1 / operand2;
                    else
                        throw "Division by zero!";
                    break;
                default:
                    throw "Invalid operator!";
            }

            operandStack.Push(result);
        }
    }

    if (!operandStack.IsEmpty()) {
        double finalResult = operandStack.Top();
        operandStack.Pop();
        return finalResult;
    } else {
        throw "Invalid expression!";
    }
}


int main() {
    try {
        string infix;
        cout << "Enter an infix expression: ";
        getline(cin, infix);

        string postfix = infixToPostfix(infix);
        cout << "Postfix expression: " << postfix << endl;

        double result = evaluatePostfix(postfix);
        cout << "Result: " << result << endl;
    } catch (const char* error) {
        cout << error << endl;
    } catch (...) {
        cout << "An unexpected error occurred." << endl;
    }

    return 0;
}
