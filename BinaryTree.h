#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include "Node.h"
using namespace std;

class BinaryTree
{
private:
    Node* root; // root of the expression tree

    void clear(Node* node); // delete tree
    void prefixHelper(Node* node, string& output) const;
    void postfixHelper(Node* node, string& output) const;
    double evaluateHelper(Node* node) const;

public:
    BinaryTree();
    ~BinaryTree();

    void setRoot(Node* ptr);
    Node* getRoot() const;

    string getPrefix() const;
    string getPostfix() const;
    double evaluate() const;
};

#endif
