struct Node
{
    int data;
    Node *next;
};

class DynamicQueue
{
private:
    Node *front; //head
    Node *rear;
    
public:
    DynamicQueue();
    ~DynamicQueue();
    bool isEmpty();
    void enqueue(int);
    int dequeue();
};
