#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main()
{
	List<int> list;
	list.print();
	list.append(2);
	list.print();
	list.append(3);
	list.append(4);
	list.append(5);
	list.print();

	List<string> sList;
	sList.append("Master Yoda:");
	sList.append("Do.");
	sList.append("Or do not.");
	sList.append("There is no try.");
	sList.print();

	/*
	list.prepend(2);
	list.print();
	list.prepend(3);
	list.prepend(4);
	list.prepend(5);
	list.print();

	sList.prepend("There is no try.");
	sList.prepend("Or do not.");
	sList.prepend("Do.");
	sList.prepend("Master Yoda:");
	sList.print();
*/
	system("pause>0");
	return 0;
}