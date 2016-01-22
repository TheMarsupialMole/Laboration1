#pragma once

//klass som beskriver en node---data---pekare till f�rra noden----pekare till n�sta noden
template <class T>
class List;

template <class T>
class Node {
	friend class List<T>;
private:
	Node<T>* prev;
	Node<T>* next;
	T data;
public:
	Node<T>* Prev();
	Node<T>* Next();
	T getData();
	Node<T>() : prev(nullptr), next(nullptr), data(0){}
	Node<T>(Node<T>* p, Node<T>* n, T data);
	~Node<T>() {}
};