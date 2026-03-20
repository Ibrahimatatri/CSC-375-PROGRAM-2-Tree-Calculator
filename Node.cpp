#include "Node.h"

Node::Node()
{
    data = "";
    left = nullptr;
    right = nullptr;
}

Node::Node(string value)
{
    data = value;
    left = nullptr;
    right = nullptr;
}

void Node::setData(string value)
{
    data = value;
}

void Node::setLeft(Node* ptr)
{
    left = ptr;
}

void Node::setRight(Node* ptr)
{
    right = ptr;
}

string Node::getData() const
{
    return data;
}

Node* Node::getLeft() const
{
    return left;
}

Node* Node::getRight() const
{
    return right;
}
