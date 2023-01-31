#include <stdexcept>
#include <iostream>

#include "./../include/Node.h"
#include "./../include/Node.cpp"
#include "./Queue.h"

template <typename T>
Queue<T> *create_queue()
{
    Queue<T> *q = new Queue<T>;
    q->front = nullptr;
    q->tail = nullptr;
    return q;
}


template <typename T>
bool empty(Queue<T> *q)
{
    // If front and tail pointers are nullptr
    if(!q->front && !q->tail) return true;
    return false;
}


template <typename T>
bool enqueue(Queue<T> *q, T value)
{
    Node<T> *node = createNode<T>(value);
    if( empty(q) ) // If the queue is empty
    {
	q->front = q->tail = node;
	return true;
    }

    q->tail->pNext = node;
    node->pPrev = q->tail;
    q->tail = node;

    return true;
}


template <typename T>
bool enqueue_steps(Queue<T> *q, T value, int &counter)
{
    counter ++;

    Node<T> *node = createNode<T>(value);
    if( empty(q) ) // If the queue is empty
    {
	q->front = q->tail = node;
	return true;
    }

    q->tail->pNext = node;
    node->pPrev = q->tail;
    q->tail = node;

    return true;
}


template <typename T>
T dequeue(Queue<T> *q)
{
    if( empty(q) )
	throw std::runtime_error("The Queue is empty.");

    // Saving the value of the front to return it
    Node<T> *tmp = q->front;
    T value = tmp->value;

    if( tmp->pNext ) // If it is not the only one
    {
	tmp->pNext->pPrev = nullptr;
	q->front = tmp->pNext;
	tmp->pNext = nullptr;
    }
    else
    {
	// Queue empty
	q->front = q->tail = nullptr;
    }

    // Deleting the previous front
    delete tmp;

    return value;
}


template <typename T>
T dequeue_steps(Queue<T> *q, int &counter)
{
    counter ++;

    if( empty(q) )
	throw std::runtime_error("The Queue is empty.");

    // Saving the value of the front to return it
    Node<T> *tmp = q->front;
    T value = tmp->value;

    if( tmp->pNext ) // If it is not the only one
    {
	tmp->pNext->pPrev = nullptr;
	q->front = tmp->pNext;
	tmp->pNext = nullptr;
    }
    else
    {
	// Queue empty
	q->front = q->tail = nullptr;
    }

    // Deleting the previous front
    delete tmp;

    return value;
}


template <typename T>
int search(Queue<T> *q, T key)
{
    // Initialize the search in front
    Node<T> *cur = q->front;

    int pos = 0;
    while( cur ) // While current node is not nullptr
    {
	T cur_val = cur->value;
	// Comparing the key with the value of
	// the current node
	if( cur_val == key) return pos;

	// If the current value is not key, 
	// increment the position and search
	// in the next node
	pos++;
	cur = cur->pNext;
    }

    delete cur;

    return -1;
}


template <typename T>
int search_steps(Queue<T> *q, T key, int &counter)
{
    // Initialize the search in front
    Node<T> *cur = q->front;

    int pos = 0;
    while( cur ) // While current node is not nullptr
    {
	counter ++;

	T cur_val = cur->value;
	// Comparing the key with the value of
	// the current node
	if( cur_val == key) return pos;

	// If the current value is not key, 
	// increment the position and search
	// in the next node
	pos++;
	cur = cur->pNext;
    }

    delete cur;

    return -1;
}


template <typename T>
T at_queue(Queue<T> *q, int pos)
{
    // Begin in queue front
    Node<T> *cur = q->front;
    int i = 0;
    // While the index is in the length of the queue
    // and the current node has a next
    while( i < pos )
    {
	i++;
	
	if(!cur->pNext) break;
	cur = cur->pNext;
    }

    if( !cur ) // If the pos is out of length
	std::runtime_error("Illegal position.");

    T value = cur->value;

    return value;
}

template <typename T>
T at_queue_steps(Queue<T> *q, int pos, int &counter)
{
    // Begin in queue front
    Node<T> *cur = q->front;
    int i = 0;
    // While the index is in the length of the queue
    // and the current node has a next
    while( i < pos )
    {
	counter ++;
	i++;

	if(!cur->pNext) break;

	cur = cur->pNext;
    }

    if( !cur ) // If the pos is out of length
	std::runtime_error("Illegal position.");
    
    T value = cur->value;

    return value;
}


template <typename T>
void print_queue(Queue<T> *q)
{
    Node<T> *cur = q->front;
    std::cout << "[";

    // While the current node is different that nullptr
    while(cur) 
    {
	std::cout << " "<< cur->value << " ";
	cur = cur->pNext;
    }
    std::cout << "]" << std::endl;

    delete cur;
}
