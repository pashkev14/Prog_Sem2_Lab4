#pragma once

#include "Item.h"

struct ListOfItems {

	Item* first;
	Item* last;

	ListOfItems();

	~ListOfItems();

	bool isEmpty();

	int getSize();

	int getSizeOfString();

	Item* getItem(const int index);

	void appendItem(Item* val);

	void deleteItem(const int index);

	void deleteList();

};