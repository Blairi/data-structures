#include <iostream>
#include <fstream>
#include "BinaryTree.cpp"
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree<int> *b = createBinaryTree<int>();
	int steps = 0;
	add_steps(b, 5, steps);
	cout << "Insert 5 -> " << steps << endl;
	steps = 0;
	add_steps(b, 4, steps);
	cout << "Insert 4 -> " << steps << endl;
	steps = 0;
	add_steps(b, 3, steps);
	cout << "Insert 3 -> " << steps << endl;
	steps = 0;
	add_steps(b, 2, steps);
	cout << "Insert 2 -> " << steps << endl;
	printInfix(b);
	steps = 0;
	deletion_steps(b->root, 2, steps);
	cout << "Deleting 2 -> " << steps << endl;
	return 0;
}
