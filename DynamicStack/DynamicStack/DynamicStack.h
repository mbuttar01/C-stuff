class DynIntStack
{
private:
// Structure for stack nodes
    struct StackNode
    {
    int value; // Value in the node
    StackNode *next; // Pointer to the next node };
    };
    StackNode *top;
    
public:

    DynIntStack()
    { top = nullptr; }
    ~DynIntStack();
    void push(int);
    int pop();
    bool isEmpty();
    int getMin();
};

