#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main()
{
	List<int> nodes;

	nodes.push_back(1);
	nodes.push_back(2);
	nodes.push_back(3);
	nodes.push_back(4);
	nodes.push_back(5);

	for (List<int>::Iterator it = nodes.begin(); it != nodes.end(); it++) {
		cout << *it << endl;
	}
	cout << "----------------" << endl;

	List<int>::Iterator itErase = nodes.begin();
	nodes.erase(itErase);
	itErase++;
	nodes.erase(itErase);
	itErase++;
	nodes.erase(itErase);
	nodes.erase(itErase);
	itErase++;

	for (List<int>::Iterator it = nodes.begin(); it != nodes.end(); it++) {
		cout << *it << endl;
	}
	cout << "----------------" << endl;

	List<int>::Iterator itInsert = nodes.begin();
	nodes.insert(itInsert, 11);
	nodes.insert(++itInsert, 22);
	nodes.insert(itInsert, 33);

	for (List<int>::Iterator it = nodes.begin(); it != nodes.end(); it++) {
		cout << *it << endl;
	}
	cout << "----------------" << endl;


	List<string> strings;
	strings.push_front("There is no try.");
	strings.push_front("Or do not.");
	strings.push_front("Do.");
	strings.push_front("Master Yoda:");

	for (List<string>::Iterator it = strings.begin(); it != strings.end(); it++) {
		cout << it->data << endl;
	}
	cout << "----------------" << endl;

	system("pause>0");
	return 0;
}