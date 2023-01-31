#include <iostream>
#include <fstream>
#include "./Queue.cpp"

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
    outdata.open( "/home/blairi/development/projects/data-structures/Queue/data/access.txt" );
    if( !outdata ) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    Queue<int> *q = create_queue<int>();
    int steps = 0;
    // Access O(n)
    for(int i = 1; i <= MAX; i++)
    {
	enqueue(q, i);
	steps = 0;
	at_queue_steps(q, i, steps);
	outdata << i << ":" << steps << endl;
    }
    outdata.close();

}
