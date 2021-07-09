// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965

#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__
#include "StaticStack.h"

namespace Queue
{
    Stack::StaticStack Create();

    bool Enqueue(Stack::StaticStack& queue, char elem);

    char Dequeue(Stack::StaticStack& queue);

    char Front(const Stack::StaticStack& queue);

    int Size(const Stack::StaticStack& queue);

    int Count(const Stack::StaticStack& queue);

    bool IsEmpty(const Stack::StaticStack& queue);

    bool Clear(Stack::StaticStack& queue);
}

#endif // __STATIC_QUEUE_H__
