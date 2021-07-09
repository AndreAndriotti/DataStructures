// ANDRE PHILIPE ANDRIOTTI DE MORAES - TIA: 32013965
// GABRIEL KAZUITI AIURA - TIA: 32047231

#include <iostream>
#include <sstream>
#include "Stack.h"

using namespace std;

void PrintStack(const Stack* stack)
{
	Node* node = stack->top;

	cout << "Stack: ";
	while (node != nullptr)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << "\n\n";
}

bool CalcOperando(Stack* stack, float value)
{
	cout << " (float: " << value << ")\n";
	Push(stack, value);

	return true;
}

bool CalcOperador(Stack* stack, string value)
{
	cout << " (operador: " << value << ")\n";

	Node* f2 = new Node;
	Node* f1 = new Node;
	float result = 0;
	
	f2 = Pop(stack);
	f1 = Pop(stack);

	if (f2 == nullptr || f1 == nullptr) return false;

	char op = value[0];
	switch (op)
	{
		case '+':
			result = f1->data + f2->data; 
			break;
		case '-':
			result = f1->data - f2->data;
			break;
		case '*':
			result = f1->data * f2->data;
			break;
		case '/': 
			result = f1->data / f2->data;
			break;
	}

	Push(stack, result);
	return true;
}

int main()
{
	Stack* stack = Create();

	cout << "Digite uma expressao pos-fixa: ";
	string input;
	getline(cin, input);
	cout << endl;

	if (input == "0")
		cout << "Fim.";
	else
	{
		istringstream iss(input);
		string str;

		bool expError = false;
		while (iss >> str)
		{
			cout << str;

			try
			{
				float value = stof(str);
				CalcOperando(stack, value);
			}
			catch (invalid_argument e)
			{
				if (str == "+" || str == "-" || str == "*" || str == "/")
				{
					if (!CalcOperador(stack, str))
					{
						expError = true;
						break;
					}
				}
				else
				{
					expError = true;
					cout << " (" << e.what() << ")\n";
					break;
				}
			}
			PrintStack(stack);
		}

		if (!expError)
		{
			float result = Pop(stack)->data;
			if(IsEmpty(stack))
				cout << "\nResultado: " << result;
			else
				cout << "\nErro na expressao.\n";
		}
		else
			cout << "\nErro na expressao.\n";
	}

	Destroy(stack);
}

// Referencia: Livro "Introducao a Estruturas de Dados com Tecnicas de 
//			   Programacao em C" - Waldemar Celes - Capitulo 15.1 ("Pilhas").
