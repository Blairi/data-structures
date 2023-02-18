#include <iostream>
#include <fstream>
#include "BinaryTree.cpp"
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree<int> *b = createBinaryTree<int>();
	add(b, 5);
	add(b, 7);
	add(b, 9);
	add(b, 1);
	printInfix(b);
	deletion(b->root, 90);
	cout << "\n";
	printInfix(b);
	return 0;
}
