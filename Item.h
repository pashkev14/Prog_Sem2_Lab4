#pragma once

#include "String.h"

struct Item {

	String* val;
	Item* next;

	Item(const int size);

	~Item();

};