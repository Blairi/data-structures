#ifndef QUEUE_H
#define QUEUE_H

#include "../include/Node.h"

template <typename T>
struct Queue{
    Node<T> *front;
    Node<T> *tail;
};

template <typename T>
Queue<T> *create_queue();

template <typename T>
bool enqueue(Queue<T> *q, T value);

template <typename T>
T dequeue(Queue<T> *q);
template <typename T>
T dequeue_steps(Queue<T> *q, int &counter);

template <typename T>
void print_queue(Queue<T> *q);

template <typename T>
bool empty(Queue<T> *q);

template <typename T>
int search(Queue<T> *q, T key);
template <typename T>
int search_steps(Queue<T> *q, T key, int &counter);

template <typename T>
T at_queue(Queue<T> *q, int pos);
template <typename T>
T at_queue_steps(Queue<T> *q, int pos, int &counter);


#endif
