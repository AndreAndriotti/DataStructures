#include "StaticQueue.h"

StaticQueue Create()
{
    StaticQueue queue = {0, 0, 0, {0}};
    return queue;
}

bool Enqueue(StaticQueue &queue, char elem)
{
    if (queue.count == Size(queue))
        return false;

    queue.values[queue.rear] = elem;

    queue.rear = (queue.rear + 1) % Size(queue);

    ++queue.rear;
    ++queue.count;

    return true;
}

char Dequeue(StaticQueue &queue)
{
    if (IsEmpty(queue))
        return '\0';

    char value = queue.values[queue.front];
    queue.values[queue.front] = '\0';

    queue.front = (queue.front + 1) % Size(queue);

    ++queue.front;
    --queue.count;

    return value;
}

char Front(const StaticQueue &queue)
{
    return IsEmpty(queue) ? '\0' : queue.values[queue.front];
}

int Size(const StaticQueue &queue)
{
    return STATIC_QUEUE_CAPACITY;
}

int Count(const StaticQueue &queue)
{
    return queue.count;
}

bool IsEmpty(const StaticQueue &queue)
{
    return queue.count == 0;
}

bool Clear(StaticQueue &queue)
{
    while (!IsEmpty(queue))
        Dequeue(queue);

    return IsEmpty(queue);
}
