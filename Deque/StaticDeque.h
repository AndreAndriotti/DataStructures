// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965
// GABRIEL KAZUITI AIURA - TIA: 32047231

#ifndef __STATIC_DEQUE_H__
#define __STATIC_DEQUE_H__

namespace Deque
{
    const int STATIC_DEQUE_CAPACITY = 8;

    struct StaticDeque
    {
            int front;
            int rear;
            int count;
            char values[STATIC_DEQUE_CAPACITY];
    };

    StaticDeque Create();

    bool InsertFront(StaticDeque& deque, char elem);

    bool InsertBack(StaticDeque& deque, char elem);

    char RemoveFront(StaticDeque& deque);

    char RemoveBack(StaticDeque& deque);

    char Front(const StaticDeque& deque);

    char Back(const StaticDeque& deque);

    int Size(const StaticDeque& deque);

    int Count(const StaticDeque& deque);

    bool IsEmpty(const StaticDeque& deque);

    bool Clear(StaticDeque& deque);
}

#endif // __STATIC_DEQUE_H__