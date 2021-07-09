// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965

#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__

namespace Stack
{

    const int STATIC_STACK_CAPACITY = 5;

    struct StaticStack
    {
        int current;
        char values[STATIC_STACK_CAPACITY];
    };

    StaticStack Create();

    bool Push(StaticStack& stack, char elem);

    char Pop(StaticStack& stack);

    char Top(const StaticStack& stack);

    int Size(const StaticStack& stack);

    int Count(const StaticStack& stack);

    bool IsEmpty(const StaticStack& stack);

    bool Clear(StaticStack& stack);

    StaticStack Reverse(Stack::StaticStack& stack);
}

#endif // __STATIC_STACK__
