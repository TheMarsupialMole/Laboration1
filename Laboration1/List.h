#pragma once
#include "Node.h"

//klass som beskriver en dubbellänkad lista och dess metoder.
template <class T>
class List {
	friend class Node<T>;
private:
	Node<T>* last = nullptr;
	Node<T>* first = nullptr;
public:
	Node<T>* push_front(T data);
	Node<T>* push_back(T data);
	void pop_front();
	void pop_back();
	Node<T>* insertafter(Node<T>* insNode, T data);
	Node<T>* insertbefore(Node<T>* insNode, T data);
	Node<T>* First();
	Node<T>* Last();
	List() :first(nullptr), last(nullptr) {}
	~List();
};
