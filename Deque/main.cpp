// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965
// GABRIEL KAZUITI AIURA - TIA: 32047231

#include "StaticDeque.h"
#include <iostream>

using namespace std;
using namespace Deque;

int Menu();

int main()
{
	setlocale(LC_ALL, "pt-BR");

	StaticDeque deque = Create();

	char elem;
	int op = 0;

	while (op != 11)
	{
		op = Menu();

		switch (op)
		{
		case 1:
			cout << ">>> Elemento a ser inserido: ";
			cin >> elem;
			InsertFront(deque, elem);
			cout << "Elemento '" << elem << "' inserido!\n\n";
			break;

		case 2:
			cout << ">>> Elemento a ser inserido: ";
			cin >> elem;
			InsertBack(deque, elem);
			cout << "Elemento '" << elem << "' inserido!\n\n";
			break;

		case 3:
			cout << "Elemento '" << RemoveFront(deque) << "' removido!\n\n";
			break;

		case 4:
			cout << "Elemento '" << RemoveBack(deque) << "' removido!\n\n";
			break;

		case 5:
			cout << "Front: " << Front(deque) << "\n\n";
			break;

		case 6:
			cout << "Back: " << Back(deque) << "\n\n";
			break;

		case 7:
			cout << "Quantidade de elementos: " << Count(deque) << "\n\n";
			break;

		case 8:
			cout << "Capacidade do deque: " << Size(deque) << "\n\n";
			break;

		case 9:
			cout << "Fila vazia? " << (IsEmpty(deque) ? "Sim" : "Não") << "\n\n";
			break;

		case 10:
			Clear(deque);
			cout << "Deque esvaziado com sucesso!\n\n";
			break;
		}
	}
}

int Menu()
{
	int op;

	cout << "=============DEQUE=============\n\n";
	cout << " [1] InsertFront\n";
	cout << " [2] InsertBack\n";
	cout << " [3] RemoveFront\n";
	cout << " [4] RemoveBack\n";
	cout << " [5] Front\n";
	cout << " [6] Back\n";
	cout << " [7] Count\n";
	cout << " [8] Size\n";
	cout << " [9] IsEmpty\n";
	cout << "[10] Clear\n";
	cout << "[11] Sair\n\n";
	cout << ">>> Escolha uma operação: ";
	cin >> op;
	cout << "===============================\n\n";

	return op;
}
