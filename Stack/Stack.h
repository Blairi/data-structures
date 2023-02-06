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
T pop_steps(Stack<T> *s, int &counter);

template <typename T>
bool push(Stack<T> *s, T value);
template <typename T>
bool push_steps(Stack<T> *s, T value, int &counter);

template <typename T>
bool empty(Stack<T> *s);

template <typename T>
void print_stack(Stack<T> *s);

template <typename T>
int search(Stack<T> *s, T key);
template <typename T>
int search_steps(Stack<T> *s, T key, int &counter);

template <typename T>
T at_stack(Stack<T> *s, int pos);
template <typename T>
T at_stack_steps(Stack<T> *s, int pos, int &counter);

#endif

