#ifndef BINARY_TREE 
#define BINARY_TREE 

template<typename T>
struct Node{
	T value;
	Node<T> *L;
	Node<T> *R;
};

template<typename T>
Node<T> *createNode(T value);


template<typename T>
struct BinaryTree{
	Node<T> *root;
};

template<typename T>
BinaryTree<T> *createBinaryTree();

template<typename T>
void add(BinaryTree<T>*bt,  T value);
template<typename T>
void addNode(BinaryTree<T>*bt,  T value, Node<T> *node);
// The add function with counter 
template<typename T>
void add_steps(BinaryTree<T>*bt,  T value, int &counter);
template<typename T>
void addNode_steps(BinaryTree<T>*bt,  T value, Node<T> *node, int &counter);

template<typename T>
void infix(BinaryTree<T>*bt, Node<T> *node);
template<typename T>
void printInfix(BinaryTree<T>*bt);

template<typename T>
Node<T> *search(BinaryTree<T> *bt, T key);
template<typename T>
Node<T> *searchBinaryTree(BinaryTree<T> *bt, Node<T> *node, T key);
template<typename T>
Node<T> *search_steps(BinaryTree<T> *bt, T key, int &counter);
template<typename T>
Node<T> *searchBinaryTree_steps(BinaryTree<T> *bt, Node<T> *node, T key, int &counter);

template<typename T>
T deletion(Node<T> *root, T key);
template<typename T>
T deletion_steps(Node<T> *root, T key, int &counter);

template<typename T>
Node<T> *access(Node<T> *root, T key);
template<typename T>
Node<T> *access_steps(Node<T> *root, T key, int &counter);

#endif
