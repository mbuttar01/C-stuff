// Specification file for the DynIntStack class
#ifndef DYNSTACK_H
#define DYNSTACK_H

template < class T >
class DynStack
{
private:
    // Structure for stack nodes
    struct StackNode
    {
        T value;        // Value in the node
        StackNode *next;  // Pointer to the next node
    };
    
    StackNode *top;      // Pointer to the stack top
    
public:
    // Constructor
    DynStack()
    {  top = 0; }
    
    // Destructor
    ~DynStack();
    
    // Stack operations
    void push( T );
    void pop( T & );
    bool isEmpty();
};
#endif 
