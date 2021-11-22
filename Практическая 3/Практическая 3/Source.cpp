#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

void addHead(Node*& head, Node*& tail, int val) // функция добавления узла в начало списка
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
void addTail(Node* head, Node*& tail, int val) // функция добавления узла в конец списка
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
void outListHead(Node* head) // вывод списка методом обхода c начала списка
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
void outListTail(Node* tail) // вывод списка методом обхода c конца списка
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
int countNodeHead(Node* head) // функция подсчёта узлов с начала списка
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
int countNodeTail(Node* tail) // функция подсчёта узлов с начала списка
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
Node* findPosHead(Node* head, int pos)	// функция поиска по позиции с начала списка
{
	while (pos > 1)
	{
		head = head->next;
		pos--;
	}
	return head;
}
Node* findDataHead(Node* head, Node* tail, int data)	// функция поиска по позиции с начала списка
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
Node* findPosTail(Node* tail, int pos)	// функция поиска по позиции с конца списка
{
	while (pos > 1)
	{
		tail = tail->prev;
		pos--;
	}
	return tail;
}
Node* findDataTail(Node* head, Node* tail, int data)	// функция поиска по позиции с начала списка
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
void insertPosHead(Node*& head, int pos, int val)	// функция добавления узла по позиции с начала списка
{
	if (pos == 1)
		return;
	Node* p = findPosHead(head, pos - 1);
	Node* p2 = findPosHead(head, pos);
	Node* temp = new Node;
	temp->data = val;
	temp->next = p2;
	temp->prev = p;
	p2->prev = temp;
	p->next = temp;
}
void insertPosTail(Node*& tail, int pos, int val)	// функция добавления узла по позиции с конца списка
{
	if (pos == 1)
		return;
	Node* p = findPosTail(tail, pos - 1);
	Node* p2 = findPosTail(tail, pos);
	Node* temp = new Node;
	temp->data = val;
	temp->prev = p2;
	temp->next = p;
	p2->next = temp;
	p->prev = temp;
}
Node* removeHead(Node*& head, Node* tail)	// функция удаления узла в начале списка
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
Node* removeTail(Node* head, Node*& tail)	// функция удаления узла в конце списка
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
void removeAll(Node*& head, Node*& tail) // функция удаления списка
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
void remove(Node*& head, Node*& tail, int pos)	// функция удаления узла в указанной позиции
{
	if (head == NULL)
		return;
	if (tail == NULL)
		return;
	Node* temp = findPosHead(head, pos);
	Node* p = findPosHead(head, pos - 1);
	Node* p2 = findPosHead(head, pos + 1);
	p->next = p2;
	p2->prev = p;
	delete temp;
}
bool isEmpty(Node* head)			// функция проверки на пустоту
{
	return head == NULL;
}