// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965

#include "StaticStack.h"
#include "StaticQueue.h"
#include <iostream>

using namespace std;

void PrintQueue(Stack::StaticStack& queue);

int main()
{
	setlocale(LC_ALL, "pt-BR");
	Stack::StaticStack queue = Queue::Create();
	
	cout << "	ENQUEUE ABC\n\n";

	cout << "Fila vazia? " << (IsEmpty(queue) ? "Sim" : "Não") << '\n';
	
	PrintQueue(queue);
	Queue::Enqueue(queue, 'A');
	PrintQueue(queue);
	Queue::Enqueue(queue, 'B');
	PrintQueue(queue);
	Queue::Enqueue(queue, 'C');
	PrintQueue(queue);

	cout << "Fila vazia? " << (IsEmpty(queue) ? "Sim" : "Não") << '\n';

	cout << "\n	DEQUEUE ABC\n\n";

	cout << "Dequeue: " << Queue::Dequeue(queue) << endl;
	PrintQueue(queue);
	cout << "Dequeue: " << Queue::Dequeue(queue) << endl;
	PrintQueue(queue);
	cout << "Dequeue: " << Queue::Dequeue(queue) << endl;
	PrintQueue(queue);

	cout << "\n	ENQUEUE XYZ\n\n";

	Queue::Enqueue(queue, 'X');
	PrintQueue(queue);
	Queue::Enqueue(queue, 'Y');
	PrintQueue(queue);
	Queue::Enqueue(queue, 'Z');
	PrintQueue(queue);

	cout << "\n	CLEAR XYZ\n\n";

	Queue::Clear(queue);
	PrintQueue(queue);



}

void PrintQueue(Stack::StaticStack& queue)
{
	cout << "Front: " << Queue::Front(queue) << " (" << Queue::Count(queue) << "/" << Queue::Size(queue) << ")\n";
}