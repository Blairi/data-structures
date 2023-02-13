#include <iostream>
#include "BinaryTree.h"

template<typename T>
Node<T> *createNode(T value)
{
	Node<T> *node = new Node<T>;
	node->value = value;
	node->L = nullptr;
	node->R = nullptr;
	return node;
}


template<typename T>
BinaryTree<T> *createBinaryTree()
{
	BinaryTree<T> *bt = new BinaryTree<T>;
	bt->root = nullptr;
	return bt;
}


template<typename T>
void add(BinaryTree<T>*bt, T value)
{
	if (!bt->root)
		bt->root = createNode(value);
	else
		addNode(bt, value, bt->root);
}


template<typename T>
void addNode(BinaryTree<T>*bt,  T value, Node<T> *node)
{
	if(value < node->value)
		if(!node->L)
			addNode(bt, value, node);
		else
			node->L = createNode(value);
	else
		if(!node->R)
			addNode(bt, value, node);
		else
			node->R = createNode(value);
}
