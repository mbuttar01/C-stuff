#include"DynamicStack.h"
#include <iostream>
using namespace std;

DynIntStack::~DynIntStack()
{
    StackNode *nodePtr = nullptr, *nextNode = nullptr;
    // Position nodePtr at the top of the stack.
     nodePtr = top;
     // Traverse the list deleting each node.
     while (nodePtr)
     {
         nextNode = nodePtr->next;
         delete nodePtr;
         nodePtr = nextNode;
     }
    
}
void DynIntStack::push(int num)
 {
     StackNode *newNode = nullptr; // Pointer to a new node
    
     // Allocate a new node and store num there.
     newNode = new StackNode;
     newNode->value = num;
    
     // If there are no nodes in the list
     // make newNode the first node.
     if (isEmpty())
        {
             top = newNode;
             newNode->next = nullptr;
        }
     else // Otherwise, insert NewNode before top.
        {
             newNode->next = top;
             top = newNode;
        }
     }

int DynIntStack::pop()
{
    StackNode *temp = nullptr; // Temporary pointer
    int character = 0;
    // First make sure the stack isn't empty.
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else // pop value off top of stack
    {
        character = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
    return character;
    
}
//***************************************************** // Member function isEmpty returns true if the stack * // is empty, or false otherwise. * //*****************************************************
bool DynIntStack::isEmpty() {
    bool status;
    if (!top)
        status = true;
    else
        status = false;
    return status; }


int DynIntStack::getMin(){
    
    StackNode* next = top;
    StackNode* curr = NULL;
    int min = 0;
    curr = next->next;
    while(curr && next)
    {
     
        if(curr->value > next->value)
        {
            min = next->value;
        }
        
        curr = curr->next;
        next = next->next;
    }
    
    return min;
}

