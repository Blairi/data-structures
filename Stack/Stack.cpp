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


template <typename T>
int search(Stack<T> *s, T key)
{
    Node<T> *cur = s->top;

    int pos = 0;
    while(cur)
    {
	T cur_value = cur->value;

	if(cur_value == key) return pos;

	pos ++;
	cur = cur->pNext;
    }

    delete cur;

    // If the key isn't in the stack
    return -1;
}


template <typename T>
T at_stack(Stack<T> *s, int pos)
{
    if(pos < 0)
	std::runtime_error("Illegal position.");

    Node<T> *cur = s->top;

    int i = 0;
    while(i < pos)
    {
	i ++;

	if(!cur->pNext) break;
	cur = cur->pNext;
    }

    if(!cur)
	std::runtime_error("Illegal position.");

    T value = cur->value;

    return value;
}
