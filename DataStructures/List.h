#pragma once

template<typename DataType> struct Node {
	DataType data;
	Node<DataType>* Next = NULL;
};

template<typename List> class ListIterator {
	using NodePointer = typename List::NodePointer;
	using DataType = typename List::DataType;
	using PointerType = DataType*;
	using ReferenceType = DataType&;
private:
	NodePointer pNode;
public:
	ListIterator(NodePointer Ptr) { pNode = Ptr; }
	ListIterator() { pNode = NULL; }
	ListIterator& operator++() {
		if (pNode != NULL) {
			pNode = pNode->Next;
		}
		return *this;
	}
	ListIterator operator++(int) {
		ListIterator Temp = *this;
		++(*this);
		return Temp;
	}
	ReferenceType operator*() const {
		return pNode->data;
	}
	NodePointer operator->() const {
		return pNode;
	}
	bool operator==(const ListIterator& Right) const {
		return pNode == Right.pNode;
	}
	bool operator!=(const ListIterator& Right) const {
		return !(pNode == Right.pNode);
	}
};

template<typename T> class List {
public:
	using DataType = T;
	using NodePointer = Node<DataType>*;
	using Iterator = ListIterator<List<DataType>>;
private:
	NodePointer Head;
public:
	List() { Head = NULL; }
	~List();
	void push_front(DataType value);
	void push_back(DataType value);
	void pop_front();
	void pop_back();
	Iterator begin() { return Iterator(Head); }
	Iterator end() { return Iterator(); }		//	nullptr
	void insert(Iterator &Where, DataType value);
	void erase(Iterator &Where);
};

template<typename DataType> List<DataType>::~List() {
	NodePointer Current = Head;
	while (Current != NULL) {
		NodePointer Temp = Current;
		Current = Current->Next;
		delete Temp;
	}
}

template<typename DataType> void List<DataType>::push_front(DataType value) {
	NodePointer NewNode = new Node<DataType>;
	NewNode->data = value;
	NewNode->Next = Head;
	Head = NewNode;
}

template<typename DataType> void List<DataType>::push_back(DataType value) {
	if (Head == NULL) {
		push_front(value);
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

template<typename DataType> void List<DataType>::pop_front() {		//	be accurate with any ListIterator pointing to Head-node
	if (Head == NULL) { return; }
	NodePointer Temp = Head;
	Head = Head->Next;
	delete Temp;
}

template<typename DataType> void List<DataType>::pop_back() {		//	be accurate with any ListIterator pointing to Tail-node
	if (Head == NULL) { return; }
	if (Head->Next == NULL) {
		pop_front();
		return;
	}
	Iterator It(Head);
	for (It; It->Next->Next != NULL; It++) {}
	NodePointer Temp = It->Next;
	It->Next = NULL;
	delete Temp;
}

template<typename DataType> void List<DataType>::insert(Iterator &Where, DataType value) {		//	places after iterator position, use push_front() to place in the beginning
	if (Where == nullptr) { return; }
	NodePointer NewNode = new Node<DataType>;
	NewNode->data = value;
	NewNode->Next = Where->Next;
	Where->Next = NewNode;
	++Where;
}

template<typename DataType> void List<DataType>::erase(Iterator &Where) {		//	removes from iterator position, pointing iterator to Next
	if (Where == nullptr) { return; }
	if (Where == Head) {
		++Where;
		pop_front();
		return;
	}
	if (Where->Next == NULL) {
		++Where;
		pop_back();
		return;
	}
	Iterator It(Head);
	for(It; Where != It->Next; ++It) {}
	NodePointer Temp = It->Next;
	It->Next = Where->Next;
	++Where;
	delete Temp;
}