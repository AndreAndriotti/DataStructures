// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965
// GABRIEL KAZUITI AIURA - TIA: 32047231

#include <iostream>
#include "LinkedList.h"

LinkedList* Create()
{
	LinkedList* list = new LinkedList;

	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;

	return list;
}

bool Destroy(LinkedList* list)
{
	Clear(list);
	delete list;
	list = nullptr;

	return true;
}

bool Insert(LinkedList* list, int elem)
{
	Node* newNode = new Node;

	newNode->data = elem;
	newNode->next = list->head;

	if (IsEmpty(list))
		list->tail = newNode;

	list->head = newNode;
	++list->count;

	return true;
}

bool Append(LinkedList* list, int elem)
{
	Node* newNode = new Node;
	
	newNode->data = elem;
	newNode->next = nullptr;

	if (IsEmpty(list))
	{
		list->head = list->tail = newNode;
	}
	else
	{
		list->tail->next = newNode;
		list->tail = newNode;
	}

	++list->count;

	return true;
}

Node* RemoveHead(LinkedList* list)
{
	Node* toRemove = list->head;

	if (list->head == list->tail)
		list->head = list->tail = nullptr;
	else
		list->head = list->head->next;

	--list->count;

	return toRemove;
}

Node* RemoveTail(LinkedList* list)
{
	if (list->head == list->tail)
		return RemoveHead(list);

	Node* toRemove = list->head;
	Node* previous = nullptr;

	while (toRemove != list->tail)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}

	previous->next = nullptr;
	list->tail = previous;
	--list->count;

	return toRemove;
}

Node* RemoveNode(LinkedList* list, int value)
{
	Node* toRemove = list->head;
	Node* previous = nullptr;

	while (toRemove != nullptr && toRemove->data != value)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}

	if (toRemove == nullptr) return nullptr;
	else if (toRemove == list->head) return RemoveHead(list);
	else if (toRemove == list->tail) return RemoveTail(list);
	else
	{
		previous->next = toRemove->next;
		--list->count;

		return toRemove;
	}
}

Node* GetHead(const LinkedList* list)
{
	return list->head;
}

Node* GetTail(const LinkedList* list)
{
	return list->tail;
}

Node* GetNode(const LinkedList* list, int value)
{
	Node* node = list->head;

	while (node != nullptr)
	{
		if (node->data == value)
			return node;

		node = node->next;
	}

	return nullptr;
}

int Count(const LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
	return list->count == 0;
}

bool Clear(LinkedList* list)
{
	Node* node = list->head;
	Node* next = nullptr;

	while (node != nullptr)
	{
		next = node->next;
		delete node;
		node = next;

		--list->count;
	}

	list->head = list->tail = nullptr;

	return IsEmpty(list);
}

bool DestroyNode(Node* node)
{
	delete node;
	node = nullptr;

	return true;
}

void Print(const LinkedList* list)
{
	Node* node = list->head;

	while (node != nullptr)
	{
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << "\n";
}