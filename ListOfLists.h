#pragma once

#include "List.h"

struct ListOfLists {

	List* first;
	List* last;

	ListOfLists();

	~ListOfLists();

	bool isEmpty();

	int getSize();

	int getSizeOfList(const int index);

	List* getList(const int index);

	void appendList(List* val);

	void deleteList(const int index);

	void deleteListOfLists();

	void swap(List* list, const int index1, const int index2);

	void reverseList(const int index);

	void mixList(const int index);

};