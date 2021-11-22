#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

void List::addHead(int val) // функция добавления узла в начало списка
{
	Node* temp = new Node;
	temp->data = val;
	if (head == NULL)
	{							//первый узел
		temp->prev = tail;
		temp->next = head;
		head = temp;
		tail = temp;
	}
	else {
		temp->next = head;
		temp->prev = tail;
		tail->next = temp;
		head->prev = temp;
		head = temp;
	}
}
void List::addTail(int val) // функция добавления узла в конец списка
{
	Node* temp = new Node;
	temp->data = val;
	if (head == NULL)
	{							//первый узел
		temp->prev = tail;
		temp->next = head;
		head = temp;
		tail = temp;
	}
	else {
		temp->next = head;
		temp->prev = tail;
		tail->next = temp;
		head->prev = temp;
		tail = temp;
	}
}
void List::outListHead() // вывод списка методом обхода c начала списка
{
	if (!head)
		return;
	cout << head->data << "  ";
	Node* temp = head->next;
	while (temp != head)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
}
void List::outListTail() // вывод списка методом обхода c конца списка
{
	if (!tail)
		return;
	cout << tail->data << "  ";
	Node* temp = tail->prev;
	while (temp != tail)
	{
		cout << temp->data << "  ";
		temp = temp->prev;
	}
}
int List::countNodeHead() // функция подсчёта узлов с начала списка
{
	if (!head)
		return 0;
	int count = 0;
	count++;
	Node* temp = head->next;
	while (temp != head)
	{
		temp = temp->next;
		count++;
	}
	return count;
}
int List::countNodeTail() // функция подсчёта узлов с начала списка
{
	if (!tail)
		return 0;
	int count = 0;
	count++;
	Node* temp = tail->prev;
	while (temp != tail)
	{
		temp = temp->prev;
		count++;
	}
	return count;
}
Node* List::findPosHead(int pos)	// функция поиска по позиции с начала списка
{
	while (pos > 1)
	{
		head = head->next;
		pos--;
	}
	return head;
}
Node* List::findDataHead(int data)	// функция поиска по позиции с начала списка
{
	Node* temp = head;
	while (temp->next != tail)
	{
		temp = temp->next;
		if (temp->data == data)
			return temp;
	}
	return NULL;
}
Node* List::findPosTail(int pos)	// функция поиска по позиции с конца списка
{
	while (pos > 1)
	{
		tail = tail->prev;
		pos--;
	}
	return tail;
}
Node* List::findDataTail(int data)	// функция поиска по позиции с начала списка
{
	Node* temp = tail;
	while (temp->prev != head)
	{
		temp = temp->prev;
		if (temp->data = data)
			return temp;
	}
	return NULL;
}
void List::insertPosHead(int pos, int val)	// функция добавления узла по позиции с начала списка
{
	if (pos == 1 || pos == countNodeTail())
		return;

	Node* node = head->prev;
	int i = 1;
	while (i != pos) {
		node = node->next;
		i++;
	}
	// 1 [] 3 4
	// *

	// 1 < 2 > 3
	// 2 < 3
	// 1 > 2
	Node* newNode = new Node();
	newNode->data = val;

	newNode->next = node->next;
	newNode->prev = node;
	
	node->next->prev = newNode;
	node->next = newNode;
	

}
void List::insertPosTail(int pos, int val)	// функция добавления узла по позиции с конца списка
{
	if (pos == 1 || pos == countNodeTail())
		return;
	Node* node = head;
	int i = 1;
	while (i != pos) {
		node = node->prev;
		i++;
	}
	Node* newNode = new Node();
	newNode->data = val;

	// 1 2 3 5 6
	// 1 2 3  []  5 6
	//       4[3] *

	newNode->next = node;
	newNode->prev = node->prev;


	node->prev->next = newNode;
	node->prev = newNode;
	
	
}

Node* List::removeHead()	// функция удаления узла в начале списка
{
	if (head == NULL)
		return NULL;
	Node* temp = head;

	head = temp->next;
	tail->next = temp->next;
	head->prev = tail;
	delete temp;
	return head;
}
Node* List::removeTail()	// функция удаления узла в конце списка
{
	if (tail == NULL)
		return NULL;
	Node* temp = tail;

	tail = temp->prev;
	head->prev = temp->prev;
	tail->next = head;
	delete temp;
	return tail;
}
void List::removeAll() // функция удаления списка
{
	Node* p, * p1;
	p = head;
	tail->next = NULL;
	head->prev = NULL;
	while (p != NULL)
	{
		p1 = p->next;
		delete p;
		p = p1;
	}
	head = NULL;
	tail = NULL;
}
void List::remove(int pos)	// функция удаления узла в указанной позиции
{
	if (head == NULL)
		return;
	if (tail == NULL)
		return;
	Node* temp = findPosHead(pos);
	Node* p = findPosHead(pos - 1);
	Node* p2 = findPosHead( pos + 1);
	p->next = p2;
	p2->prev = p;
	delete temp;
}
bool List::isEmpty()			// функция проверки на пустоту
{
	return head == NULL;
}