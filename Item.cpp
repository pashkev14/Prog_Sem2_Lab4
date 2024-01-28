#include "Item.h"

Item::Item(const int size) {
	this->val = new String(size);
	this->next = nullptr;
}

Item::~Item() {
	delete this->val;
}