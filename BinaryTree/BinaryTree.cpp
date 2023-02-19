#include <iostream>
#include <stdexcept>
#include <queue>
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
void addNode(BinaryTree<T>*bt, T value, Node<T> *node)
{
	if(value < node->value)
		if(node->L)
			addNode(bt, value, node->L);
		else
			node->L = createNode(value);
	else
		if(node->R)
			addNode(bt, value, node->R);
		else
			node->R = createNode(value);
}


template<typename T>
void infix(BinaryTree<T>*bt, Node<T> *node)
{
	if(node)
	{
		if(node->L)
			infix(bt, node->L);

		std::cout << node->value << std::endl;

		if(node->R)
			infix(bt, node->R);
	}
}


template<typename T>
void printInfix(BinaryTree<T>*bt)
{
	if(bt->root)
		infix(bt, bt->root);
}


template<typename T>
T deletion(Node<T> *root, T key)
{
    if (!root->L && !root->R) {
        if (root->value == key)
            return root->value;
        else
            std::runtime_error("Key not found");
    }
    Node<T> *key_node = nullptr;
    Node<T>* temp;
    Node<T>* last;
		std::queue<Node<T>*> q;
    q.push(root);
    // Do level order traversal to find deepest
    // node(temp), node to be deleted (key_node)
    // and parent of deepest node(last)
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->value == key)
            key_node = temp;
        if (temp->L) {
            last = temp; // storing the parent node
            q.push(temp->L);
        }
        if (temp->R) {
            last = temp; // storing the parent node
            q.push(temp->R);
        }
    }
    if (key_node) {
        key_node->value
            = temp->value; // replacing key_node's data to
                          // deepest node's data
        if (last->R == temp)
            last->R = nullptr;
        else
            last->L = nullptr;
        delete (temp);
    }
    return root->value;
}


template<typename T>
Node<T> *searchBinaryTree(BinaryTree<T> *bt, Node<T> *node, T key)
{
    if(!node || key == node->value)
        return node;

    if(key < node->value)
        return searchBinaryTree(bt, node->L, key);
    else
        return searchBinaryTree(bt, node->R, key);

    return nullptr;
}

template<typename T>
Node<T> *search(BinaryTree<T> *bt, T key)
{
    if(bt->root)
        return searchBinaryTree(bt, bt->root, key);
    else
        return nullptr;
}


template<typename T>
Node<T> *access(Node<T> *root, T key)
{
    if (!root || root->value == key) {
        return root;
    }
    if (key < root->value) {
        return access(root->L, key);
    }
    return access(root->R, key);
}
