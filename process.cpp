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
	files->logFile << "Программа начала свою работу.\nПроизводится попытка открыть входной файл.\n";
	if (files->inFile.is_open()) {
		files->logFile << "Производится попытка считать код действия и индекс.\n";
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
				files->outFile << "Сформирован следующий список:\n";
				files->logFile << "Сформирован следующий список:\n";
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
					files->outFile << "Считанный индекс оказался больше фактического размера списка. Дальнейшие операции не имеют смысла.\n";
					files->logFile << "Считанный индекс оказался больше фактического размера списка. Дальнейшие операции не будут выполняться.\n";
				}
				else {
					if (mode == 1) {
						files->outFile << "Выбран разворот списков (режим 1). Все списки, начиная с " << index + 1 << "-ого по счету, будут перевернуты в обратную сторону.\n";
						files->logFile << "Производится разворот всех списков, начиная с " << index + 1 << "-ого по счету.\n";
						reverseLists(list, index);
					}
					else {
						files->outFile << "Выбрана перемешка списков (режим 2). Все списки с четным числом элементов, начиная с " << index + 1 << "-ого по счету, будут попарно перемешаны.\n";
						files->logFile << "Производится перемешка всех списков с четным числом элементов, начиная с " << index + 1 << "-ого по счету.\n";
						mixLists(list, index);
					}
					files->outFile << "Итоговый список:\n";
					files->logFile << "Итоговый список:\n";
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
				files->outFile << "Список пуст. Дальнейшие операции с ним не имеют смысла.";
				files->logFile << "Список пуст. Дальнейшие операции не будут выполняться.\n";
			}
			files->outFile << "Проверка на корректное удаление:\nДо:\n" << list->first << ' ' << list->last;
			files->logFile << "Проверка на корректное удаление:\nДо:\n" << list->first << ' ' << list->last;
			delete list;
			files->outFile << "\nПосле:\n" << list->first << ' ' << list->last;
			files->logFile << "\nПосле:\n" << list->first << ' ' << list->last << '\n';
		}
		else {
			files->outFile << "Ошибка: считан неверный код действия (введите либо 1, либо 2).";
			files->logFile << "Считан неверный код действия.\n";
		}
	}
	else {
		files->outFile << "Ошибка: входной файл не найден.";
		files->logFile << "Входной файл не найден.\n";
	}
	files->logFile << "Программа завершила свою работу.";
	delete files;
}