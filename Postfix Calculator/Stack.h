// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965
// GABRIEL KAZUITI AIURA - TIA: 32047231

#ifndef __STACK_H__
#define __STACK_H__

const int STACK_CAPACITY = 8;

struct Node
{
	float data;
	Node* next;
};

struct Stack
{
    int count;
	Node* top;
};

Stack* Create();

bool Destroy(Stack* stack);

bool Push(Stack* stack, float elem);

Node* Pop(Stack* stack);

Node* Top(const Stack* stack);

int Count(const Stack* stack);

bool IsEmpty(const Stack* stack);

bool Clear(Stack* stack);

bool DestroyNode(Node* node);

#endif // __STACK_H__
