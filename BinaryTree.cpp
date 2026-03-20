#include "BinaryTree.h"
#include <cstdlib>

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    clear(root); // free memory
}

void BinaryTree::setRoot(Node* ptr)
{
    root = ptr;
}

Node* BinaryTree::getRoot() const
{
    return root;
}

void BinaryTree::clear(Node* node)
{
    if (node != nullptr)
    {
        clear(node->getLeft());
        clear(node->getRight());
        delete node; // delete after children
    }
}

void BinaryTree::prefixHelper(Node* node, string& output) const
{
    if (node != nullptr)
    {
        output += node->getData() + " "; // root first
        prefixHelper(node->getLeft(), output);
        prefixHelper(node->getRight(), output);
    }
}

void BinaryTree::postfixHelper(Node* node, string& output) const
{
    if (node != nullptr)
    {
        postfixHelper(node->getLeft(), output);
        postfixHelper(node->getRight(), output);
        output += node->getData() + " "; // root last
    }
}

double BinaryTree::evaluateHelper(Node* node) const
{
    // if leaf node, it's just a number
    if (node->getLeft() == nullptr && node->getRight() == nullptr)
    {
        return atof(node->getData().c_str());
    }

    double leftValue = evaluateHelper(node->getLeft());
    double rightValue = evaluateHelper(node->getRight());
    string op = node->getData();

    // basic operations
    if (op == "+")
    {
        return leftValue + rightValue;
    }
    else if (op == "-")
    {
        return leftValue - rightValue;
    }
    else if (op == "*")
    {
        return leftValue * rightValue;
    }
    else
    {
        return leftValue / rightValue; // assume valid input
    }
}

string BinaryTree::getPrefix() const
{
    string output = "";
    prefixHelper(root, output);

    if (!output.empty())
    {
        output.pop_back(); // remove extra space
    }

    return output;
}

string BinaryTree::getPostfix() const
{
    string output = "";
    postfixHelper(root, output);

    if (!output.empty())
    {
        output.pop_back();
    }

    return output;
}

double BinaryTree::evaluate() const
{
    if (root == nullptr)
    {
        return 0;
    }

    return evaluateHelper(root);
}
