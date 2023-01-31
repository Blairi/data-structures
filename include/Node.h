#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node{
    T value;
    Node<T> *pNext;
    Node<T> *pPrev;
};

template <typename T>
Node<T> *createNode(T value);

#endif
