#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include "List.h"
#include "Node.h"
#include <iostream>

//metod som lägger till en node först i listan
template <class T>
Node<T>* List<T>::push_front(T data){
	Node<T>* newNode = new Node<T>(nullptr, nullptr, data);//skapa en Node

	if (first == nullptr){//om inget finns  Listan
		first = newNode; // låt first peka på den nyskapade Noden
		last = newNode; // låt last peka på den nyskapade Noden
	}
	else{ // Listan är inte tom
		first->prev = newNode;
		newNode->next = List<T>::first;
		first = newNode;
	}
	return newNode;
}

//metod som lägger till en node sist i listan
template <class T>
Node<T>* List<T>::push_back(T data){
	Node<T>* newNode = new Node<T>(nullptr, nullptr, data);//skapa en Node

	if (first == nullptr) {//om inget finns  Listan
		first = newNode; // låt first peka på den nyskapade Noden
		last = newNode; // låt last peka på den nyskapade Noden
	}
	else { // Listan är inte tom
		last->next = newNode;
		newNode->prev = List<T>::last;
		last = newNode;
	}
	return newNode;
}

//metod som tar bort det första elementet i listan
template <class T>
void List<T>::pop_front(){
	if (first != nullptr) {	//kolla om det finns nån node i listan...om inte...gör ingenting
		if (first->next != nullptr) {	//kolla om det finns någon node efter det första i listan.
			first = first->next;
			delete first->prev;
			first->prev = nullptr;
		}
		else {							//om det inte finns någon node efter den första så nollställ rubbet
			delete first;
			first = nullptr;
			last = nullptr;
		}
	}
}

//metod som tar bort den sista noden i listan
template <class T>
void List<T>::pop_back(){
	if (last != nullptr) {	//kolla om det finns nån node i listan...om inte...gör ingenting
		if (last->prev != nullptr) {		//kolla om det finns någon node före den sista i listan
			last = last->prev;
			delete last->next;
			last->next = nullptr;
		}
		else {							//om det inte finns någon node före den sista så nollställ rubbet
			delete last;
			first = nullptr;
			last = nullptr;
		}
	}
}

//metod son fäller in en ny node efter den node som kommer in som parameter
template <class T>
Node<T>* List<T>::insertafter(Node<T>* insertionNode, T data){
	Node<T>* newNode = new Node<T>(nullptr, nullptr, data);	//skapa en node med försedd data (parameter data)
	Node<T>* nextNode = insertionNode->next;	//skapa pekare till noden efter isertionnode
	insertionNode->next = newNode;	//låt insertionnoden peka på den nya noden
	newNode->prev = insertionNode;	//låt den nya noden peka på insertionnoden
	newNode->next = nextNode;	//låt den nya noden peka på den node som tidigare var efter insertionnoden
	nextNode->prev = newNode;	//låt den node som tidigare var efter insertionnoden peka på den nya noden
	return newNode;
}

//metod son fäller in en ny node före den node som kommer in som parameter
template <class T>
Node<T>* List<T>::insertbefore(Node<T>* insertionNode, T data){
	Node<T>* newNode = new Node<T>(nullptr, nullptr, data);	//skapa en node med försedd data (parameter data)
	Node<T>* prevNode = insertionNode->prev;	//skapa pekare till noden före isertionnode
	insertionNode->prev = newNode;	//låt insertionnoden peka på den nya noden
	newNode->next = insertionNode;	//låt den nya noden peka på insertionnoden
	newNode->prev = prevNode;	//låt den nya noden peka på den node som tidigare var före insertionnoden
	prevNode->next = newNode;	//låt den node som tidigare var före insertionnoden peka på den nya noden
	return newNode; nullptr;
}

//metod som retrunerar en pekare till den första noden i listan
template <class T>
Node<T>* List<T>::First(){
	return first;
}

//metod som returnerar en pekare till den sista noden i listan
template <class T>
Node<T>* List<T>::Last(){
	return last;
}

//destruktor
template <class T>
List<T>::~List() {
		while (first != nullptr) {
			List<T>::pop_back();
		}
		List<T>::pop_front();
}
