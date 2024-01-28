#include "ListOfLists.h"

ListOfLists::ListOfLists() {
	this->first = nullptr;
	this->last = nullptr;
}

ListOfLists::~ListOfLists() {
	this->deleteListOfLists();
}

bool ListOfLists::isEmpty() {
	return this->first == nullptr;
}

int ListOfLists::getSize() {
	int length = 0;
	List* p = this->first;
	while (p != nullptr) {
		++length;
		p = p->next;
	}
	return length;
}

int ListOfLists::getSizeOfList(const int index) {
	if (index < 0 || index >= this->getSize()) return -1;
	return this->getList(index)->val->getSizeOfString();
}

List* ListOfLists::getList(const int index) {
	if (index < 0 || index >= this->getSize()) return nullptr;
	int pos = 0;
	List* p = this->first;
	while (pos != index) {
		++pos;
		p = p->next;
	}
	return p;
}

void ListOfLists::appendList(List* val) {
	if (this->isEmpty()) {
		this->first = val;
		this->last = val;
	}
	else {
		this->last->next = val;
		this->last = val;
	}
}

void ListOfLists::deleteList(const int index) {
	if (this->isEmpty()) return;
	int size = this->getSize();
	if (index < 0 || index >= size) return;
	if (size == 1) {
		this->last = nullptr;
		delete this->first;
		this->first = nullptr;
	}
	else {
		List* del = this->getList(index);
		if (index == 0) {
			this->first = del->next;
			delete del;
		}
		else if (index == size - 1) {
			this->last = this->getList(index - 1);
			this->last->next = nullptr;
			delete del;
		}
		else {
			List* prev = this->getList(index - 1);
			prev->next = this->getList(index + 1);
			delete del;
			prev = nullptr;
		}
		del = nullptr;
		if (this->getSize() == 1) {
			this->last = this->first;
		}
	}
}

void ListOfLists::deleteListOfLists() {
	int curIndex = this->getSize() - 1;
	while (this->first != nullptr) {
		this->deleteList(curIndex);
		--curIndex;
	}
}

void ListOfLists::swap(List* list, const int index1, const int index2) {
	Item* toSwap1 = list->val->getItem(index1);
	Item* toSwap2 = list->val->getItem(index2);
	if (list->val->getSize() == 2) {
		toSwap2->next = toSwap1;
		toSwap1->next = nullptr;
		list->val->first = toSwap2;
		list->val->last = toSwap1;
	}
	else if (toSwap1 == list->val->first && toSwap2 == list->val->last) {
		Item* next1 = list->val->getItem(index1 + 1);
		Item* prev2 = list->val->getItem(index2 - 1);
		toSwap2->next = next1;
		prev2->next = toSwap1;
		toSwap1->next = nullptr;
		list->val->first = toSwap2;
		list->val->last = toSwap1;
	}
	else if (toSwap1 == list->val->first && toSwap2 != list->val->last) {
		Item* next1 = list->val->getItem(index1 + 1);
		Item* prev2 = list->val->getItem(index2 - 1);
		Item* next2 = list->val->getItem(index2 + 1);
		prev2->next = toSwap1;
		toSwap1->next = next2;
		toSwap2->next = next1;
		list->val->first = toSwap2;
	}
	else if (toSwap1 != list->val->first && toSwap2 == list->val->last) {
		Item* prev1 = list->val->getItem(index1 - 1);
		Item* next1 = list->val->getItem(index1 + 1);
		Item* prev2 = list->val->getItem(index2 - 1);
		prev1->next = toSwap2;
		toSwap2->next = next1;
		prev2->next = toSwap1;
		toSwap1->next = nullptr;
		list->val->last = toSwap1;
	}
	else {
		Item* prev1 = list->val->getItem(index1 - 1);
		Item* next1 = list->val->getItem(index1 + 1);
		Item* prev2 = list->val->getItem(index2 - 1);
		Item* next2 = list->val->getItem(index2 + 1);
		prev1->next = toSwap2;
		toSwap2->next = next1;
		prev2->next = toSwap1;
		toSwap1->next = next2;
	}
}

void ListOfLists::reverseList(const int index) {
	if (index < 0 || index >= this->getSize()) return;
	List* list = this->getList(index);
	Item* cur = list->val->first;
	Item* tmp = nullptr;
	Item* prev = nullptr;
	while (cur != nullptr) {
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	list->val->first = prev;
}

void ListOfLists::mixList(const int index) {
	List* list = this->getList(index);
	int size = list->val->getSize();
	if (index < 0 || index >= this->getSize()) return;
	if (size % 2 != 0) return;
	if (size == 2) {
		this->swap(list, 0, 1);
		return;
	}
	for (int i = 0; i < size / 2; ++i) this->swap(list, i, i + 2);
}