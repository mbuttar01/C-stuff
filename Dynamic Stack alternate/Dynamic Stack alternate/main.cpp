#include <iostream>
#include "DynStack.h"
using namespace std;

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template < class T >
DynStack<T>::~DynStack()
{
    StackNode *nodePtr, *nextNode;
    
    // Position nodePtr at the top of the stack.
    nodePtr = top;
    
    // Traverse the list deleting each node.
    while (nodePtr != 0)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************
template < class T >
void DynStack<T>::push( T num )
{
    StackNode *newNode; // Pointer to a new node
    
    // Allocate a new node and store num there.
    newNode = new StackNode;
    newNode->value = num;
    
    // If there are no nodes in the list
    // make newNode the first node.
    if (isEmpty())
    {
        top = newNode;
        newNode->next = 0;
    }
    else  // Otherwise, insert NewNode before top.
    {
        newNode->next = top;
        top = newNode;
    }
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
//****************************************************
template < class T >
void DynStack<T>::pop( T &num )
{
    StackNode *temp; // Temporary pointer
    
    // First make sure the stack isn't empty.
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else  // pop value off top of stack
    {
        num = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************
template < class T >
bool DynStack<T>::isEmpty()
{
    bool status;
    
    if (!top)
        status = true;
    else
        status = false;
    
    return status;
}
