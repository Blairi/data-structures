#include "./Node.h"

template <typename T>
Node<T> *createNode(T value)
{
    Node<T> *pNode = new Node<T>;
    pNode->value = value;
    pNode->pNext = nullptr;
    pNode->pPrev = nullptr;
    return pNode;
}
