#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
private:
    string data;   // stores number or operator
    Node* left;    // left child
    Node* right;   // right child

public:
    Node();
    Node(string value);

    void setData(string value);
    void setLeft(Node* ptr);
    void setRight(Node* ptr);

    string getData() const;
    Node* getLeft() const;
    Node* getRight() const;
};

#endif
