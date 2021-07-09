// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965
// GABRIEL KAZUITI AIURA - TIA: 32047231

#include "Stack.h"

Stack* Create()
{
    Stack* stack = new Stack;

    stack->count = 0;
    stack->top = nullptr;

    return stack;
}

bool Destroy(Stack* stack)
{
    Clear(stack);
    delete stack;
    stack = nullptr;

    return true;
}

bool Push(Stack* stack, float elem)
{
    Node* newNode = new Node;

    newNode->data = elem;
    newNode->next = stack->top;

    stack->top = newNode;

    ++stack->count;

    return true;
}

Node* Pop(Stack* stack)
{
    if (IsEmpty(stack))
    {
        return nullptr;
    }

    Node* toRemove = stack->top;

    stack->top = toRemove->next;

    --stack->count;

    return toRemove;
}

Node* Top(const Stack* stack)
{
    return stack->top;
}

int Count(const Stack* stack)
{
    return stack->count;
}

bool IsEmpty(const Stack* stack)
{
    return stack->count == 0;
}

bool Clear(Stack* stack)
{
    while (!IsEmpty(stack))
        DestroyNode(Pop(stack));

    return IsEmpty(stack);
}

bool DestroyNode(Node* node)
{
    delete node;
    node = nullptr;

    return true;
}