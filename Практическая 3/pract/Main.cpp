#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	List ls;

	ls.addHead(2);
	ls.addTail(5);
	ls.addTail(6);
	ls.addHead(1);
	ls.insertPosHead(3, 3);
	ls.insertPosTail(3, 4);
	cout << endl;
	ls.outListHead();

}