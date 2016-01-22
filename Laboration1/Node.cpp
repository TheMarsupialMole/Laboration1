#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include "Node.h"
#include "List.h"

template <class T>
Node<T>::Node(Node<T>* p, Node<T>* n, T da) {
	prev = p;
	next = n;
	data = da;
}

template <class T>
Node<T>* Node<T>::Prev(){
	return prev;
}

template <class T>
Node<T>* Node<T>::Next(){
	return next;
}

template <class T>
T Node<T>::getData() {
	return data;
}



