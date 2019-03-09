
#include <iostream>
#include "DynamicQueue.h"
using namespace std;


DynamicQueue::DynamicQueue()
{
    front = NULL;
    rear = NULL;
}

DynamicQueue::~DynamicQueue()
{
    while (!isEmpty())
        dequeue();
}

bool DynamicQueue::isEmpty()
{
    return (!front); // can also use rear.
}

void DynamicQueue::enqueue(int data)
{
    
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
    rear->next = newNode;
    rear = newNode;
    }
}

int DynamicQueue::dequeue()
{
    int number;
    if (isEmpty())
        cout << "The queue is already empty\n";
    else
    {
        Node *tempNode = front;
        int num = 0;
        tempNode->data = num;
        front = front->next;
        delete tempNode;
        num = number;
    }
    return number;
}
