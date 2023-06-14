#pragma once

#include <iostream>

template<typename DataType> struct Node {
	DataType data;
	Node<DataType>* Next = NULL;
};

template<typename DataType> class List {
	using NodePointer = Node<DataType>*;
private:
	NodePointer Head;
public:
	List() { Head = NULL; }
	~List();
	void prepend(DataType value);
	void append(DataType value);
	void print();
};

template<typename DataType> List<DataType>::~List() {
	NodePointer Current = Head;
	while (Current != NULL) {
		NodePointer Temp = Current;
		Current = Current->Next;
		delete Temp;
	}
}

template<typename DataType> void List<DataType>::prepend(DataType value) {
	NodePointer NewNode = new Node<DataType>;
	NewNode->data = value;
	NewNode->Next = Head;
	Head = NewNode;
}

template<typename DataType> void List<DataType>::append(DataType value) {
	if (Head == NULL) {
		prepend(value);
		return;
	}
	NodePointer Current = Head;
	NodePointer NewNode = new Node<DataType>;
	NewNode->data = value;
	while (Current->Next != NULL) {
		Current = Current->Next;
	}
	Current->Next = NewNode;
}

template<typename DataType> void List<DataType>::print() {
	NodePointer Ptr = Head;
	while (Ptr != NULL) {
		std::cout << Ptr->data << std::endl;
		Ptr = Ptr->Next;
	}
}