#ifndef STACK_H
#define STACK_H

// simple stack using linked list
template <class T>
class Stack
{
private:
    class StackNode
    {
    public:
        T data;
        StackNode* next;

        StackNode(T value)
        {
            data = value;
            next = nullptr;
        }
    };

    StackNode* top; // top of stack

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        // clear everything
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    void push(T value)
    {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
    }

    T pop()
    {
        if (isEmpty())
        {
            return T(); // just return default if empty
        }

        StackNode* temp = top;
        T value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    T peek() const
    {
        if (isEmpty())
        {
            return T();
        }

        return top->data;
    }
};

#endif
