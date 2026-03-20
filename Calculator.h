#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include "BinaryTree.h"
#include "Stack.h"
using namespace std;

class Calculator
{
private:
    bool isOperator(string token) const;
    bool isDigitChar(char ch) const;
    int precedence(string op) const;
    string trimTrailingZeros(double value) const;

    void processOperator(Stack<Node*>& values, Stack<string>& ops);
    BinaryTree* buildExpressionTree(string expression);

public:
    void run(); // main loop
};

#endif
