#include <stdexcept>
#include <iostream>

#include "./../include/Node.h"
#include "./../include/Node.cpp"
#include "./Stack.h"

template <typename T>
Stack<T> *create_stack()
{
    Stack<T> *s = new Stack<T>;
    s->top = nullptr;

    return s;
}


template <typename T>
T pop(Stack<T> *s)
{
    if( empty(s) ) // If the stack is empty
	throw std::runtime_error("The Stack is empty");

    Node<T> *node_tmp = s->top;
    T value = node_tmp->value;

    // If there is more than one element in the stack
    if(node_tmp->pNext)
	s->top = node_tmp->pNext;
    // If only there an element in the stack
    else
	s->top = nullptr;

    return value;
}


template <typename T>
bool push(Stack<T> *s, T value)
{
    Node<T> *node = createNode<T>(value);
    if( empty(s) ) // If the stack is empty
    {
	s->top = node;
	return true;
    }

    node->pNext = s->top;
    s->top = node;
    return true;
}


template <typename T>
bool empty(Stack<T> *s)
{
    // If top is nullptr
    return !s->top;
}


template <typename T>
void print_stack(Stack<T> *s)
{
    Node<T> *cur = s->top;

    std::cout << "[";
    // While the current node exists
    while(cur)
    {
	std::cout << " " << cur->value << " ";
	cur = cur->pNext;
    }
    std::cout << "]" << std::endl;

    delete cur;
}
