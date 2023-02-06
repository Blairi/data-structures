#include <iostream>
#include <fstream>
#include "./Stack.cpp"

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
    outdata.open( "/home/blairi/development/projects/data-structures/Stack/data/access.txt" );
    if( !outdata ) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    Stack<int> *s = create_stack<int>();
    int steps = 0;
    // Access O(n)
    for(int i = 1; i <= MAX; i++)
    {
	push(s, i);
	steps = 0;
	at_stack_steps(s, i, steps);
	outdata << i << ":" << steps << endl;
    }
    outdata.close();

    outdata.open( "/home/blairi/development/projects/data-structures/Stack/data/search.txt" );
    s = create_stack<int>();
    steps = 0;
    // Search O(n)
    for(int i = 1; i <= MAX; i++)
    {
	push(s, i);
	steps = 0;
	search_steps(s, 1, steps);
	outdata << i << ":" << steps << endl;
    }
    outdata.close();
    
    outdata.open( "/home/blairi/development/projects/data-structures/Stack/data/deletion.txt" );
    steps = 0;
    // Deletion O(1)
    for(int i = 1; i <= MAX; i++)
    {
	steps = 0;
	pop_steps(s, steps);
	outdata << i << ":" << steps << endl;
    }
    outdata.close();

    outdata.open( "/home/blairi/development/projects/data-structures/Stack/data/insertion.txt" );
    s = create_stack<int>();
    steps = 0;
    // Insertion O(1)
    for(int i = 1; i <= MAX; i++)
    {
	steps = 0;
	push_steps(s, i, steps);
	outdata << i << ":" << steps << endl;
    }
    outdata.close();
}
