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
#include "Node.cpp"
#include "List.cpp"
#include <iostream>

void test()
{
	List<int> l;
	l.push_back(3);
}

int main() {
	test();
	List<int>* lst = new List<int>();
	lst->push_front(5);
	lst->push_front(8);
	lst->push_front(2);
	lst->push_front(9);
	Node<int>* nptr = lst->push_back(11);
	lst->push_back(12);
	Node<int>* nptr2 = lst->push_back(13);
	lst->push_back(14);
	lst->insertafter(nptr, 22);
	lst->insertbefore(nptr2, 44);
	lst->pop_front();
	lst->pop_back();
	//lst->pop_back();
	//lst->pop_back();
	//lst->pop_back();
	//lst->pop_back();
	//lst->pop_back();
	//lst->pop_back();
	//lst->pop_back();
	//lst->pop_back();
	//lst->pop_back();


	if (lst->First()) {
		Node<int>* f = lst->First();
		while (f->Next() != nullptr) {
			std::cout << "prev: " << f->Prev() << std::endl;
			std::cout << "Node adress : " << f << " --- value : " << f->getData() << std::endl;
			std::cout << "next: " << f->Next() << std::endl << std::endl;
			f = f->Next();
		}
		std::cout << "prev: " << f->Prev() << std::endl;
		std::cout << "Node adress : " << f << " --- value : " << f->getData() << std::endl;
		std::cout << "next: " << f->Next() << std::endl << std::endl;

	}
	delete lst;
	std::cin.get();
	_CrtDumpMemoryLeaks();
}
