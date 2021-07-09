// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965
// GABRIEL KAZUITI AIURA - TIA: 32047231

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct Node
{
	int ID;
	std::string name;
	Node* previous;
	Node* next;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};

LinkedList* Create();

bool Destroy(LinkedList* list);

bool Insert(LinkedList* list, int ID, std::string name);

bool Append(LinkedList* list, int ID, std::string name);

bool InsertMiddle(LinkedList* list, int ID, std::string name, int value);

Node* RemoveHead(LinkedList* list);

Node* RemoveTail(LinkedList* list);

Node* RemoveNode(LinkedList* list, int value);

Node* GetHead(const LinkedList* list);

Node* GetTail(const LinkedList* list);

Node* GetNode(const LinkedList* list, int value);

int Count(const LinkedList* list);

bool IsEmpty(const LinkedList* list);

bool Clear(LinkedList* list);

bool DestroyNode(Node* node);

#endif // __LINKED_LIST_H__
