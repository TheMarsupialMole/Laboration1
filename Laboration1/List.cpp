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

//metod som l�gger till en node f�rst i listan
template <class T>
Node<T>* List<T>::push_front(T data){
	Node<T>* newNode = new Node<T>(nullptr, nullptr, data);//skapa en Node

	if (first == nullptr){//om inget finns  Listan
		first = newNode; // l�t first peka p� den nyskapade Noden
		last = newNode; // l�t last peka p� den nyskapade Noden
	}
	else{ // Listan �r inte tom
		first->prev = newNode;
		newNode->next = List<T>::first;
		first = newNode;
	}
	return newNode;
}

//metod som l�gger till en node sist i listan
template <class T>
Node<T>* List<T>::push_back(T data){
	Node<T>* newNode = new Node<T>(nullptr, nullptr, data);//skapa en Node

	if (first == nullptr) {//om inget finns  Listan
		first = newNode; // l�t first peka p� den nyskapade Noden
		last = newNode; // l�t last peka p� den nyskapade Noden
	}
	else { // Listan �r inte tom
		last->next = newNode;
		newNode->prev = List<T>::last;
		last = newNode;
	}
	return newNode;
}

//metod som tar bort det f�rsta elementet i listan
template <class T>
void List<T>::pop_front(){
	if (first != nullptr) {	//kolla om det finns n�n node i listan...om inte...g�r ingenting
		if (first->next != nullptr) {	//kolla om det finns n�gon node efter det f�rsta i listan.
			first = first->next;
			delete first->prev;
			first->prev = nullptr;
		}
		else {							//om det inte finns n�gon node efter den f�rsta s� nollst�ll rubbet
			delete first;
			first = nullptr;
			last = nullptr;
		}
	}
}

//metod som tar bort den sista noden i listan
template <class T>
void List<T>::pop_back(){
	if (last != nullptr) {	//kolla om det finns n�n node i listan...om inte...g�r ingenting
		if (last->prev != nullptr) {		//kolla om det finns n�gon node f�re den sista i listan
			last = last->prev;
			delete last->next;
			last->next = nullptr;
		}
		else {							//om det inte finns n�gon node f�re den sista s� nollst�ll rubbet
			delete last;
			first = nullptr;
			last = nullptr;
		}
	}
}

//metod son f�ller in en ny node efter den node som kommer in som parameter
template <class T>
Node<T>* List<T>::insertafter(Node<T>* insertionNode, T data){
	Node<T>* newNode = new Node<T>(nullptr, nullptr, data);	//skapa en node med f�rsedd data (parameter data)
	Node<T>* nextNode = insertionNode->next;	//skapa pekare till noden efter isertionnode
	insertionNode->next = newNode;	//l�t insertionnoden peka p� den nya noden
	newNode->prev = insertionNode;	//l�t den nya noden peka p� insertionnoden
	newNode->next = nextNode;	//l�t den nya noden peka p� den node som tidigare var efter insertionnoden
	nextNode->prev = newNode;	//l�t den node som tidigare var efter insertionnoden peka p� den nya noden
	return newNode;
}

//metod son f�ller in en ny node f�re den node som kommer in som parameter
template <class T>
Node<T>* List<T>::insertbefore(Node<T>* insertionNode, T data){
	Node<T>* newNode = new Node<T>(nullptr, nullptr, data);	//skapa en node med f�rsedd data (parameter data)
	Node<T>* prevNode = insertionNode->prev;	//skapa pekare till noden f�re isertionnode
	insertionNode->prev = newNode;	//l�t insertionnoden peka p� den nya noden
	newNode->next = insertionNode;	//l�t den nya noden peka p� insertionnoden
	newNode->prev = prevNode;	//l�t den nya noden peka p� den node som tidigare var f�re insertionnoden
	prevNode->next = newNode;	//l�t den node som tidigare var f�re insertionnoden peka p� den nya noden
	return newNode; nullptr;
}

//metod som retrunerar en pekare till den f�rsta noden i listan
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
