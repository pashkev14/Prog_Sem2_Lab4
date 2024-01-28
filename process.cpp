#include "process.h"

const unsigned int N = 5;

void reverseLists(ListOfLists* list, const int index) {
	for (int i = index; i < list->getSize(); ++i) list->reverseList(i);
}

void mixLists(ListOfLists* list, const int index) {
	for (int i = index; i < list->getSize(); ++i) list->mixList(i);
}

void process() {
	Files* files = new Files;
	files->logFile << "��������� ������ ���� ������.\n������������ ������� ������� ������� ����.\n";
	if (files->inFile.is_open()) {
		files->logFile << "������������ ������� ������� ��� �������� � ������.\n";
		int mode;
		files->inFile >> mode;
		if (mode == 1 || mode == 2) {
			int index;
			files->inFile >> index;
			files->inFile.unsetf(std::ios::skipws);
			char tmp;
			ListOfLists* list = new ListOfLists;
			List* listItem = new List;
			Item* item = new Item(N);
			int charsCount = 0, blocksCount = 0, strCount = 0;
			files->inFile >> tmp;
			do {
				files->inFile >> tmp;
				if (files->inFile.eof()) {
					if (charsCount || blocksCount || strCount) {
						listItem->val->appendItem(item);
						list->appendList(listItem);
						listItem = nullptr;
						item = nullptr;
						charsCount = 0;
						++blocksCount;
						++strCount;
					}
					else {
						delete listItem;
						delete item;
					}
					break;
				}
				if (tmp == '\n') {
					listItem->val->appendItem(item);
					++blocksCount;
					list->appendList(listItem);
					++strCount;
					item = nullptr;
					listItem = nullptr;
					item = new Item(N);
					listItem = new List;
					charsCount = 0;
				}
				else {
					if (charsCount == N) {
						listItem->val->appendItem(item);
						++blocksCount;
						item = nullptr;
						item = new Item(N);
						charsCount = 0;
					}
					item->val->text[charsCount] = tmp;
					item->val->text[charsCount + 1] = '\0';
					++charsCount;
				}
			} 
			while (true);
			if (list->first != nullptr) {
				files->outFile << "����������� ��������� ������:\n";
				files->logFile << "����������� ��������� ������:\n";
				List* tmpList = list->first;
				while (tmpList != nullptr) {
					Item* tmpItem = tmpList->val->first;
					while (tmpItem != nullptr) {
						int i = 0;
						while (tmpItem->val->text[i] != '\0') {
							files->outFile << tmpItem->val->text[i];
							files->logFile << tmpItem->val->text[i];
							++i;
						}
						files->outFile << "->";
						files->logFile << "->";
						tmpItem = tmpItem->next;
					}
					files->outFile << "NULL\n|\nV\n";
					files->logFile << "NULL\n|\nV\n";
					tmpList = tmpList->next;
				}
				files->outFile << "NULL\n";
				files->logFile << "NULL\n";
				if (index < 0 || index >= strCount) {
					files->outFile << "��������� ������ �������� ������ ������������ ������� ������. ���������� �������� �� ����� ������.\n";
					files->logFile << "��������� ������ �������� ������ ������������ ������� ������. ���������� �������� �� ����� �����������.\n";
				}
				else {
					if (mode == 1) {
						files->outFile << "������ �������� ������� (����� 1). ��� ������, ������� � " << index + 1 << "-��� �� �����, ����� ����������� � �������� �������.\n";
						files->logFile << "������������ �������� ���� �������, ������� � " << index + 1 << "-��� �� �����.\n";
						reverseLists(list, index);
					}
					else {
						files->outFile << "������� ��������� ������� (����� 2). ��� ������ � ������ ������ ���������, ������� � " << index + 1 << "-��� �� �����, ����� ������� ����������.\n";
						files->logFile << "������������ ��������� ���� ������� � ������ ������ ���������, ������� � " << index + 1 << "-��� �� �����.\n";
						mixLists(list, index);
					}
					files->outFile << "�������� ������:\n";
					files->logFile << "�������� ������:\n";
					List* tmpList = list->first;
					while (tmpList != nullptr) {
						Item* tmpItem = tmpList->val->first;
						while (tmpItem != nullptr) {
							int i = 0;
							while (tmpItem->val->text[i] != '\0') {
								files->outFile << tmpItem->val->text[i];
								files->logFile << tmpItem->val->text[i];
								++i;
							}
							files->outFile << "->";
							files->logFile << "->";
							tmpItem = tmpItem->next;
						}
						files->outFile << "NULL\n|\nV\n";
						files->logFile << "NULL\n|\nV\n";
						tmpList = tmpList->next;
					}
					files->outFile << "NULL\n";
					files->logFile << "NULL\n";
				}
			}
			else {
				files->outFile << "������ ����. ���������� �������� � ��� �� ����� ������.";
				files->logFile << "������ ����. ���������� �������� �� ����� �����������.\n";
			}
			files->outFile << "�������� �� ���������� ��������:\n��:\n" << list->first << ' ' << list->last;
			files->logFile << "�������� �� ���������� ��������:\n��:\n" << list->first << ' ' << list->last;
			delete list;
			files->outFile << "\n�����:\n" << list->first << ' ' << list->last;
			files->logFile << "\n�����:\n" << list->first << ' ' << list->last << '\n';
		}
		else {
			files->outFile << "������: ������ �������� ��� �������� (������� ���� 1, ���� 2).";
			files->logFile << "������ �������� ��� ��������.\n";
		}
	}
	else {
		files->outFile << "������: ������� ���� �� ������.";
		files->logFile << "������� ���� �� ������.\n";
	}
	files->logFile << "��������� ��������� ���� ������.";
	delete files;
}