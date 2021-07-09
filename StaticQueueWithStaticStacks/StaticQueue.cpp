// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965

#include "StaticQueue.h"
#include "StaticStack.h"

namespace Queue
{
    Stack::StaticStack Create()
    {
        return Stack::Create();
    }

    bool Enqueue(Stack::StaticStack& queue, char elem)
    {
        if (Queue::Count(queue) == Queue::Size(queue))
            return false;

        Stack::StaticStack aux_stack = Stack::Reverse(queue);
        Stack::Push(aux_stack, elem);
        queue = Stack::Reverse(aux_stack);

        return true;
    }

    char Dequeue(Stack::StaticStack& queue)
    {
        return Stack::Pop(queue);
    }

    char Front(const Stack::StaticStack& queue)
    {
        return Queue::IsEmpty(queue) ? '\0' : queue.values[queue.current-1];
    }

    int Size(const Stack::StaticStack& queue)
    {
        return Stack::STATIC_STACK_CAPACITY;
    }

    int Count(const Stack::StaticStack& queue)
    {
        return queue.current;
    }

    bool IsEmpty(const Stack::StaticStack& queue)
    {
        return queue.current == 0;
    }

    bool Clear(Stack::StaticStack& queue)
    {
        while (!Queue::IsEmpty(queue))
            Dequeue(queue);

        return Queue::IsEmpty(queue);
    }
}