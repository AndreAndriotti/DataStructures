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

bool Insert(LinkedList* list, int ID, std::string name)
{
	Node* newNode = new Node;

	newNode->ID = ID;
	newNode->name = name;
	newNode->previous = list->tail;
	newNode->next = list->head;

	if (IsEmpty(list))
	{
		list->head = list->tail = newNode;
	}
	else
	{
		list->tail->next = newNode;
		list->head->previous = newNode;
		list->head = newNode;
	}

	++list->count;

	return true;
}

bool Append(LinkedList* list, int ID, std::string name)
{
	Node* newNode = new Node;

	newNode->ID = ID;
	newNode->name = name;
	newNode->previous = list->tail;
	newNode->next = list->head;

	if (IsEmpty(list))
	{
		list->head = list->tail = newNode;
	}
	else
	{
		list->head->previous = newNode;
		list->tail->next = newNode;
		list->tail = newNode;
	}

	++list->count;

	return true;
}

bool InsertMiddle(LinkedList* list, int ID, std::string name, int value)
{
	if (IsEmpty(list))
		return Insert(list, ID, name);
	
	Node* newNode = new Node;

	newNode->ID = ID;
	newNode->name = name;

	Node* temp = list->head;

	for (int i = 0; i < list->count; ++i)
	{
		if (temp->ID == value)
			break;

		temp = temp->next;
	}

	if (temp->ID != value) return false;
	else if (temp == list->tail) return Append(list, ID, name);
	else
	{
		newNode->previous = temp;
		newNode->next = temp->next;

		temp->next->previous = newNode;
		temp->next = newNode;
		

		++list->count;

		return true;
	}
}

Node* RemoveHead(LinkedList* list)
{
	if (IsEmpty(list))
		return nullptr;

	Node* toRemove = list->head;

	if (list->head == list->tail)
		list->head = list->tail = nullptr;
	else
	{
		list->head = list->head->next;
		list->head->previous = list->tail;
		list->tail->next = list->head;
	}

	--list->count;
	toRemove->previous = nullptr;
	toRemove->next = nullptr;

	return toRemove;
}

Node* RemoveTail(LinkedList* list)
{
	if (list->head == list->tail)
		return RemoveHead(list);

	Node* toRemove = list->tail;
	list->tail = list->tail->previous;
	list->tail->next = list->head;
	list->head->previous = list->tail;

	--list->count;
	toRemove->previous = nullptr;
	toRemove->next = nullptr;

	return toRemove;
}

Node* RemoveNode(LinkedList* list, int ID)
{
	Node* toRemove = list->head;

	for(int i = 0; i < list->count; ++i)
	{
		if (toRemove->ID == ID)
			break;

		toRemove = toRemove->next;
	}

	if (toRemove->ID != ID) return nullptr;
	else if (toRemove == list->head) return RemoveHead(list);
	else if (toRemove == list->tail) return RemoveTail(list);
	else
	{
		toRemove->previous->next = toRemove->next;
		toRemove->next->previous = toRemove->previous;

		--list->count;
		toRemove->previous = nullptr;
		toRemove->next = nullptr;

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

Node* GetNode(const LinkedList* list, int ID)
{
	Node* node = list->head;

	for (int i = 0; i < list->count; ++i)
	{
		if (node->ID == ID)
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

	while (!IsEmpty(list))
	{
		next = node->next;
		DestroyNode(node);
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

