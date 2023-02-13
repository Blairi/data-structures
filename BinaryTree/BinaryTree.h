#ifndef BINARY_TREE 
#define BINARY_TREE 

template<typename T>
struct Node{
	T value;
	Node<T> L;
	Node<T> R;
};

template<typename T>
Node<T> *createNode(T value);


template<typename T>
struct BinaryTree{
	Node<T> root;
};

template<typename T>
BinaryTree<T> *createBinaryTree();

template<typename T>
void add(BinaryTree<T>*bt,  T value);


#endif
