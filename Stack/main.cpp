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
    
    int x = search(s, 412);
    cout << x << endl;
    cout << at_stack(s, x) << endl;
}
