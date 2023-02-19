#include <iostream>
#include <fstream>
#include "BinaryTree.cpp"
#include "BinaryTree.h"

using namespace std;

const int MAX = 1000;

void func();

int main()
{
  func();
	return 0;
}

void func()
{
    ofstream outdata;
    outdata.open( "/home/blairi/development/projects/data-structures/BinaryTree/data/access.txt" );
    if( !outdata ) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

		BinaryTree<int> *bt = createBinaryTree<int>();
    int steps = 0;

    // Access O(n)
    for(int i = 1; i <= MAX; i++)
    {
			add(bt, i);
			steps = 0;
			access_steps(bt->root, i, steps);
			outdata << i << ":" << steps << endl;
    }
    outdata.close();

    outdata.open( "/home/blairi/development/projects/data-structures/BinaryTree/data/search.txt" );
    steps = 0;
    // Search O(n)
    for(int i = 1; i <= MAX; i++)
    {
      steps = 0;
    	search_steps(bt, i, steps);
      outdata << i << ":" << steps << endl;
    }
    outdata.close();
    
    outdata.open( "/home/blairi/development/projects/data-structures/BinaryTree/data/deletion.txt" );
    steps = 0;
    // Deletion O(1)
    for(int i = MAX; i > 0; i--)
    {
    	steps = 0;
    	deletion_steps(bt->root, i, steps);
    	outdata << i << ":" << steps << endl;
    }
    outdata.close();

    outdata.open( "/home/blairi/development/projects/data-structures/BinaryTree/data/insertion.txt" );
		bt = createBinaryTree<int>();
    steps = 0;
    // Insertion O(1)
    for(int i = 1; i <= MAX; i++)
    {
    	steps = 0;
      add_steps(bt, i, steps);
    	outdata << i << ":" << steps << endl;
    }
    outdata.close();
}
