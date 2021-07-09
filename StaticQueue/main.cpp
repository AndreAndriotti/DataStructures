#include <iostream>
#include "StaticQueue.h"

using namespace std;

void PrintQueue(const StaticQueue& queue)
{
	cout << "Front: " << Front(queue) << " (" << Count(queue) << "/" << Size(queue) << ")\n";
}

int main()
{
	setlocale(LC_ALL, "pt_BR");

	StaticQueue queue = Create();
	PrintQueue(queue);

	Enqueue(queue, '@');
	PrintQueue(queue);

	Enqueue(queue, 'X');
	PrintQueue(queue);

	Enqueue(queue, 'Y');
	PrintQueue(queue);

	cout << "Fila vazia? " << (IsEmpty(queue) ? "Sim" : "Não") << '\n';

	char temp;
	for (int i = 0; i < Size(queue); ++i)
	{
		temp = Dequeue(queue);
		if (temp == '\0')
			break;
		cout << "Dequeue: " << temp << '\n';
		PrintQueue(queue);
	}

	Clear(queue);
	cout << "Fila vazia? " << (IsEmpty(queue) ? "Sim" : "Não") << '\n';
}
