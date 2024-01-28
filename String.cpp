#include "String.h"

String::String(const int size) {
	this->text = new char[size + 1];
	this->text[0] = '\0';
	this->mark = '\0';
}

String::~String() {
	delete[] this->text;
}

int String::getSize() {
	int i = 0;
	while (this->text[i++] != this->mark);
	return i;
}