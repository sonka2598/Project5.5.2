#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int getLevel(int index) {
	if (index == 0) 
		return 0;
	return (int)log2(index + 1);
}

void printElement(vector<int>& heap, int index) {
	int level = getLevel(index);

	if (index == 0) {
		cout << level << " root " << heap[index];
		return;
	}

	int parentIndex = (index - 1) / 2;
	string role = (index % 2 == 1) ? "left" : "right";
	cout << level << " " << role << "(" << heap[parentIndex] << ") " << heap[index];
}

void printPyramid(vector<int>& heap) {
	for (int i = 0; i < heap.size(); i++) {
		printElement(heap, i);
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	vector<int> heap = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

	cout << "Исходный массив: ";
	for (int x = 0; x < heap.size(); x++)
		cout << x << " ";
	cout << endl << "Пирамида:" << endl;
	printPyramid(heap);
	cout << endl;

	int currentIndex = 0;
	string command;

	while (true) {
		cout << "Вы находитесь здесь: ";
		printElement(heap, currentIndex);
		cout << endl;

		cout << "Введите команду: ";
		cin >> command;
		if (command == "x") {
			break;
		}
		else if (command == "up") {
			if (currentIndex == 0) {
				cout << "Ошибка! Отсутствует родитель" << endl;
			}
			else {
				currentIndex = (currentIndex - 1) / 2;
				cout << "Ок" << endl;
			}
		}
		else if (command == "left") {
			int leftIndex = 2 * currentIndex + 1;
			if (leftIndex >= heap.size()) {
				cout << "Ошибка! Отсутствует левый потомок" << endl;
			}
			else {
				currentIndex = leftIndex;
				cout << "Ок" << endl;
			}
		}
		else if (command == "right") {
			int rightIndex = 2 * currentIndex + 2;
			if (rightIndex >= heap.size()) {
				cout << "Ошибка! Отсутствует правый потомок" << endl;
			}
			else {
				currentIndex = rightIndex;
				cout << "Ок" << endl;
			}
		}
		else {
			cout << "Ошибка! Неизвестная команда" << endl;
		}
	}
	return 0;
}
