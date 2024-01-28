#include "ListOfItems.h"

ListOfItems::ListOfItems() {
	this->first = nullptr;
	this->last = nullptr;
}

ListOfItems::~ListOfItems() {
	this->deleteList();
}

bool ListOfItems::isEmpty() {
	return this->first == nullptr;
}

int ListOfItems::getSize() {
	int length = 0;
	Item* p = this->first;
	while (p != nullptr) {
		++length;
		p = p->next;
	}
	return length;
}

int ListOfItems::getSizeOfString() {
	int length = 0;
	Item* p = this->first;
	while (p != nullptr) {
		length += p->val->getSize();
	}
	return length;
}

Item* ListOfItems::getItem(const int index) {
	if (index < 0 || index >= this->getSize()) return nullptr;
	int pos = 0;
	Item* p = this->first;
	while (pos != index) {
		++pos;
		p = p->next;
	}
	return p;
}

void ListOfItems::appendItem(Item* val) {
	if (this->isEmpty()) {
		this->first = val;
		this->last = val;
	}
	else {
		this->last->next = val;
		this->last = val;
	}
}

void ListOfItems::deleteItem(const int index) {
	if (this->isEmpty()) return;
	int size = this->getSize();
	if (index < 0 || index >= size) return;
	if (size == 1) {
		this->last = nullptr;
		delete this->first;
		this->first = nullptr;
	}
	else {
		Item* del = this->getItem(index);
		if (index == 0) {
			this->first = del->next;
			delete del;
		}
		else if (index == size - 1) {
			this->last = this->getItem(index - 1);
			this->last->next = nullptr;
			delete del;
		}
		else {
			Item* prev = this->getItem(index - 1);
			prev->next = this->getItem(index + 1);
			delete del;
			prev = nullptr;
		}
		del = nullptr;
		if (this->getSize() == 1) {
			this->last = this->first;
		}
	}
}

void ListOfItems::deleteList() {
	int curIndex = this->getSize() - 1;
	while (this->first != nullptr) {
		this->deleteItem(curIndex);
		--curIndex;
	}
}