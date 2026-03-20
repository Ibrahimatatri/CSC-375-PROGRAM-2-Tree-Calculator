#include "Calculator.h"
#include <iostream>
#include <sstream>
using namespace std;

bool Calculator::isOperator(string token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool Calculator::isDigitChar(char ch) const
{
    return ch >= '0' && ch <= '9';
}

int Calculator::precedence(string op) const
{
    if (op == "+" || op == "-")
    {
        return 1;
    }
    else if (op == "*" || op == "/")
    {
        return 2;
    }

    return 0;
}

string Calculator::trimTrailingZeros(double value) const
{
    ostringstream out;
    out << value;
    string result = out.str();

    // clean up decimals like 5.0000 -> 5
    if (result.find('.') != string::npos)
    {
        while (!result.empty() && result[result.length() - 1] == '0')
        {
            result.erase(result.length() - 1, 1);
        }

        if (!result.empty() && result[result.length() - 1] == '.')
        {
            result.erase(result.length() - 1, 1);
        }
    }

    return result;
}

void Calculator::processOperator(Stack<Node*>& values, Stack<string>& ops)
{
    string op = ops.pop();

    Node* right = values.pop(); // right child
    Node* left = values.pop();  // left child

    Node* newNode = new Node(op);
    newNode->setLeft(left);
    newNode->setRight(right);

    values.push(newNode); // push back to stack
}

BinaryTree* Calculator::buildExpressionTree(string expression)
{
    Stack<Node*> values;   // numbers
    Stack<string> ops;     // operators

    int i = 0;

    while (i < expression.length())
    {
        if (expression[i] == ' ')
        {
            i++;
        }
        else if (expression[i] == '(')
        {
            ops.push("(");
            i++;
        }
        else if (expression[i] == ')')
        {
            // solve until matching (
            while (!ops.isEmpty() && ops.peek() != "(")
            {
                processOperator(values, ops);
            }

            if (!ops.isEmpty())
            {
                ops.pop(); // remove (
            }

            i++;
        }
        else if (isDigitChar(expression[i]))
        {
            string number = "";

            // build full number (handles multi-digit)
            while (i < expression.length() && isDigitChar(expression[i]))
            {
                number += expression[i];
                i++;
            }

            Node* newNode = new Node(number);
            values.push(newNode);
        }
        else
        {
            string currentOp = "";
            currentOp += expression[i];

            // handle precedence
            while (!ops.isEmpty() && ops.peek() != "(" &&
                   precedence(ops.peek()) >= precedence(currentOp))
            {
                processOperator(values, ops);
            }

            ops.push(currentOp);
            i++;
        }
    }

    // finish remaining ops
    while (!ops.isEmpty())
    {
        processOperator(values, ops);
    }

    BinaryTree* tree = new BinaryTree();
    tree->setRoot(values.pop());

    return tree;
}

void Calculator::run()
{
    string expression;
    char choice = 'y';

    cout << "GREETINGS....WELCOME To MY TREE CALCULATOR" << endl;

    while (choice == 'y' || choice == 'Y')
    {
        cout << endl;
        cout << "Please enter an infix expression using only the following characters" << endl;
        cout << "(0-9, +, -, *, /, (, and )):" << endl;

        getline(cin, expression);

        BinaryTree* tree = buildExpressionTree(expression);

        cout << "Prefix: " << tree->getPrefix() << endl;
        cout << "Postfix: " << tree->getPostfix() << endl;
        cout << "Result: " << trimTrailingZeros(tree->evaluate()) << endl;

        delete tree; // free tree

        cout << "Would you like to enter another expression (y/n)?: ";
        cin >> choice;
        cin.ignore(); // clear newline
    }

    cout << "Thank you for using my program!" << endl;
}
