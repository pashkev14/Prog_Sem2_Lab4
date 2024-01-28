#pragma once

struct String {

	char* text;
	char mark;

	String(const int size);

	~String();

	int getSize();

};