/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#define SIZE 100

// hàm nhập dữ liệu vào
void getArrayElements(ifstream& ifs, int* const arr, int& size);
// hàm hiển thị dữ liệu ra màn hình
void showArrayElements(const int* const arr, const int size);
// hàm xóa bỏ các phần tử trùng nhau trong mảng
void removeDuplicatedElements(int* const arr, int& n);

int main() {
	int k; // số bộ test
	int arr[SIZE];
	int n; // số phần tử thực tế
	ifstream ifs("input5.txt");
	// đọc số bộ test:
	ifs >> k;
	int i = 1;
	while (k--) { // duyệt và thực hiện chương trình với từng bộ test
		getArrayElements(ifs, arr, n);
		cout << "Test " << i++ << ": " << endl;
		removeDuplicatedElements(arr, n);
		showArrayElements(arr, n);
	}
	ifs.close();
	return 0;
}

void getArrayElements(ifstream& ifs, int* const arr, int& size) {
	ifs >> size;
	for (int i = 0; i < size; i++) {
		ifs >> *(arr + i);
	}
}

void showArrayElements(const int* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

void sortDESC(int* const arr, const int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (*(arr + j) > *(arr + j - 1)) {
				swap(*(arr + j), *(arr + j - 1));
			}
		}
	}
}

void removeDuplicatedElements(int* const arr, int& n) {
	// khai báo nguyên mẫu:
	bool isExisted(const int* const, const int, const int);
	void removeElement(int* const, int&, int);
	for (int i = 0; i < n; i++) {
		if (isExisted(arr, i, *(arr + i))) {
			removeElement(arr, n, i);
			i--;
		}
	}
}

void removeElement(int* const arr, int& n, int position) {
	for (int i = position; i < n - 1; i++) {
		*(arr + i) = *(arr + i + 1);
	}
	n--;
}

bool isExisted(const int* const arr, const int n, const int x) {
	for (int i = 0; i < n; i++) {
		if (*(arr + i) == x) {
			return true;
		}
	}
	return false;
}