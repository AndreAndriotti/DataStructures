#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__

// Define uma pilha usando um vetor(array).

// tamanho da pilha --> inteiro
// <tipo> vetor[i] --> dados que serão manipulados

const int STATIC_STACK_CAPACITY = 8;

struct StaticStack
{
    int current; // Topo da pilha
    char values[STATIC_STACK_CAPACITY]; // Dados da pilha
};

StaticStack Create();

bool Push(StaticStack &stack, char elem);

char Pop(StaticStack &stack);

char Top(const StaticStack &stack);

int Size(const StaticStack &stack);

int Count(const StaticStack &stack);

bool IsEmpty(const StaticStack &stack);

bool Clear(StaticStack &stack);


#endif // __STATIC_STACK__
