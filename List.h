#pragma once

#include "ListOfItems.h"

struct List {
	
	ListOfItems* val;
	List* next;

	List();

	~List();

};