#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Node* head = NULL;
	Node* tail = NULL;
	int number; int count = 0;
	int position;
	addHead(head, tail, 4);
	addHead(head, tail, -8);
	addHead(head, tail, 5);
	addTail(head, tail, 7);
	cout << "Вставка числа в начало: "; cin >> number;
	addHead(head, tail, number);
	outListHead(head);
	cout << "\nВставка числа в конец: "; cin >> number;
	addTail(head, tail, number);
	outListHead(head);
	cout << "\nВставка числа в позицию 3: "; cin >> number;
	insertPosHead(head, 3, number);
	outListHead(head);
	cout << "\nВставка числа в позицию 4 c конца списка: "; cin >> number;
	insertPosTail(tail, 4, number);
	outListHead(head);
	cout << "\nУдаление узла с начала списка\n";
	removeHead(head, tail);
	outListHead(head);
	cout << "\nУдаление узла с конца списка\n";
	removeTail(head, tail);
	outListHead(head); cout << endl;
	outListTail(tail);
	count = countNodeHead(head);
	cout << "\nКоличество узлов = " << count << endl;
	cout << "Поиск числа: "; cin >> number;
	if (findDataHead(head, tail, number) != nullptr)
		cout << "Число " << findDataHead(head, tail, number)->data << " найдено " << findDataHead(head, tail, number) << endl;
	cout << "Поиск числа по позиции: "; cin >> position;
	if (findPosHead(head, position) != nullptr)
		cout << "Число " << findPosHead(head, position)->data << " найдено " << findPosHead(head, position) << endl;
	remove(head, tail, 4);
	removeAll(head, tail);
	cout << "Список удалён" << endl;
	cout << head << ' ' << tail;
}