#include "List.h"

List::List() {
	this->val = new ListOfItems;
	this->next = nullptr;
}

List::~List() {
	delete this->val;
}