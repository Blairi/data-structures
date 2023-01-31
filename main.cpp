#include <iostream>
#include "./include/Node.cpp"
#include "./Queue/Queue.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    Queue<int> *q = create_queue<int>();
    cout << empty(q) << endl;
    enqueue(q, 12);
    print_queue(q);
    cout << empty(q) << endl;
    enqueue(q, 14);
    enqueue(q, 15);
    print_queue(q);
    cout << "Front: " << q->front->value << endl;
    cout << "Tail: " << q->tail->value << endl;

    cout << "Dequeue: " << dequeue(q) << endl;
    cout << "Front: " << q->front->value << endl;
    cout << "Tail: " << q->tail->value << endl;

    cout << "Searching 15" << endl;
    int i = search(q, 15);
    print_queue(q);
    cout << "15 => " << i << endl;
    cout << i << ":" << at_queue(q, i) << endl;
    print_queue(q);

}
