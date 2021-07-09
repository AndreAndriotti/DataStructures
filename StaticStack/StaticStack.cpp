#include "StaticStack.h"

/* const int STATIC_STACK_CAPACITY = 8;

struck StaticStack
{
    int current; // Topo da pilha
    char values[STATIC_STACK_CAPACITY]; // Dados da pilha
}; */

StaticStack Create()
{
    StaticStack stack = { 0, { 0 } };
    return stack;
}

bool Push(StaticStack &stack, char elem)
{
    if (stack.current == STATIC_STACK_CAPACITY)
    {
        return false;
    }
    stack.values[stack.current] = elem;
    ++stack.current;

    return true;
}

char Pop(StaticStack &stack)
{
    if (IsEmpty(stack))
    {
        return '\0';
    }

    char temp = stack.values[stack.current - 1];
    stack.values[stack.current - 1] = '\0';
    --stack.current;

    return temp;
}

char Top(const StaticStack &stack)
{
    if (IsEmpty(stack))
    {
        return '\0';
    }

    return stack.values[stack.current-1];
}

int Size(const StaticStack &stack)
{
    return sizeof(stack.values) / sizeof(stack.values[0]);
}

int Count(const StaticStack &stack)
{
    return stack.current;
}

bool IsEmpty(const StaticStack &stack)
{
    return stack.current == 0;
}

bool Clear(StaticStack &stack)
{
    /*for(int i = 0; i < STATIC_STACK_CAPACITY; ++i)
    {
       stack.values[i] = '\0';
    }
    stack.current = 0;*/

    while (!IsEmpty(stack))
        Pop(stack);

    return IsEmpty(stack);
}
