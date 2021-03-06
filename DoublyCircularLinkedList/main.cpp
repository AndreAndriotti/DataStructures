// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965
// GABRIEL KAZUITI AIURA - TIA: 32047231

#include <iostream>
#include <clocale>
#include "LinkedList.h"

using namespace std;

void Print(const LinkedList* list)
{
	Node* node = list->head;

	for (int i = 0; i < list->count; ++i)
	{
		std::cout << "[" << node->ID << "] " << node->name << "\n";
		node = node->next;
	}
	std::cout << "\n";
}

void PrintReverse(const LinkedList* list)
{
	Node* node = list->tail;

	for (int i = list->count; i > 0; --i)
	{
		std::cout << "[" << node->ID << "] " << node->name << "\n";
		node = node->previous;
	}
	std::cout << "\n";
}

void PrintDoubleListInfo(const LinkedList* list)
{
	if (IsEmpty(list))
	{
		cout << "Lista vazia!\n";
	}
	else
	{
		cout << "Lista:\n";
		Print(list);
		cout << "Lista invertida:\n";
		PrintReverse(list);
	}
}

int main()
{
	setlocale(LC_ALL, "pt_BR");

	cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular Linked List)*** \n";

	LinkedList * list = Create();
	PrintDoubleListInfo(list);

	Insert(list, 1, "Carol");
	Insert(list, 2, "Eric");
	Insert(list, 3, "John");
	Append(list, 4, "Leo");
	Append(list, 5, "Julia");
	Append(list, 6, "Lisa");
	PrintDoubleListInfo(list);

	Clear(list);
	PrintDoubleListInfo(list);

	Insert(list, 11, "Paulo");
	Append(list, 22, "Thomas");
	Insert(list, 33, "Olga");
	Append(list, 44, "Bia");
	Insert(list, 55, "Angela");
	Append(list, 66, "Karen");
	Insert(list, 77, "Adauto");
	PrintDoubleListInfo(list);

	Node* temp = RemoveNode(list, 44);
	cout << "Nó removido -> id: " << temp->ID << ", name: " << temp->name << '\n';
	DestroyNode(temp);
	PrintDoubleListInfo(list);

	temp = RemoveHead(list);
	cout << "Nó removido -> id: " << temp->ID << ", name: " << temp->name << '\n';
	DestroyNode(temp);
	PrintDoubleListInfo(list);

	temp = RemoveTail(list);
	cout << "Nó removido -> id: " << temp->ID << ", name: " << temp->name << '\n';
	DestroyNode(temp);
	PrintDoubleListInfo(list);

	Destroy(list);

	cout << "Fim.\n";
}
