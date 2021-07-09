// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965
// GABRIEL KAZUITI AIURA - TIA: 32047231

#include "StaticDeque.h"

namespace Deque
{
    StaticDeque Create()
    {
        StaticDeque deque = { 0, 0, 0, {0} };
        return deque;
    }

    bool InsertFront(StaticDeque& deque, char elem)
    {
        if (deque.count == Size(deque))
            return false;

        if (deque.front == 0)
            deque.front = Size(deque)-1;
        else
            --deque.front;

        deque.values[deque.front] = elem;

        ++deque.count;

        return true;
    }

    bool InsertBack(StaticDeque& deque, char elem)
    {
        if (deque.count == Size(deque))
            return false;

        deque.values[deque.rear] = elem;

        deque.rear = (deque.rear + 1) % Size(deque);

        ++deque.count;

        return true;
    }

    char RemoveFront(StaticDeque& deque)
    {
        if (IsEmpty(deque))
            return '\0';

        char value = deque.values[deque.front];
        deque.values[deque.front] = '\0';

        deque.front = (deque.front + 1) % Size(deque);

        --deque.count;

        return value;
    }

    char RemoveBack(StaticDeque& deque)
    {
        if (IsEmpty(deque))
            return '\0';

        if (deque.rear == 0)
            deque.rear = Size(deque) - 1;
        else
            --deque.rear;

        char value = deque.values[deque.rear];
        deque.values[deque.rear] = '\0';

        --deque.count;

        return value;
    }

    char Front(const StaticDeque& deque)
    {
        return IsEmpty(deque) ? '\0' : deque.values[deque.front];
    }

    char Back(const StaticDeque& deque)
    {
        if (IsEmpty(deque))
            return '\0';
        else
        {
            if (deque.rear == 0)
                return deque.values[Size(deque) - 1];
            else
                return deque.values[deque.rear - 1];
        }
    }

    int Size(const StaticDeque& deque)
    {
        return STATIC_DEQUE_CAPACITY;
    }

    int Count(const StaticDeque& deque)
    {
        return deque.count;
    }

    bool IsEmpty(const StaticDeque& deque)
    {
        return deque.count == 0;
    }

    bool Clear(StaticDeque& deque)
    {
        while (!IsEmpty(deque))
            RemoveFront(deque);

        return IsEmpty(deque);
    }
}
