#include <iostream>
#include <fstream>
#include "./Stack.cpp"

using namespace std;

int main()
{
    Stack<int> *s = create_stack<int>();
    push(s, 12);
    push(s, 23);
    push(s, 412);

    print_stack(s);
    int counter = 0;
    search_steps(s, 12, counter);
    cout << counter << endl;
}
