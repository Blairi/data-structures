#ifndef STACK_H
#define STACK_H

#include "../include/Node.h"

template <typename T>
struct Stack{
    Node<T> *top;
};

template <typename T>
Stack<T> *create_stack();

template <typename T>
T pop(Stack<T> *s);

template <typename T>
bool push(Stack<T> *s, T value);

template <typename T>
bool empty(Stack<T> *s);

template <typename T>
void print_stack(Stack<T> *s);

#endif

