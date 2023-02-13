#include <iostream>
#include <fstream>
#include "BinaryTree.cpp"
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree<int> *b = createBinaryTree<int>();
	add(b, 5);
	cout << b->root->value << endl;
	return 0;
}
