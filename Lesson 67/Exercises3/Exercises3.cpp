/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <fstream>
using namespace std;

#define SIZE 100

// hàm nhập dữ liệu vào
void getArrayElements(ifstream& ifs, int* const arr, int& size);
// hàm hiển thị dữ liệu ra màn hình
void showArrayElements(const int* const arr, const int size);
// hàm chèn mảng arr2 vào giữa mảng arr1:
void insertAtMiddle(int* const arr1, int& m, 
	const int* const arr2, const int n);

int main() {
	int k; // số bộ test
	int arr1[SIZE];
	int arr2[SIZE];
	int m, n; // số phần tử thực tế
	ifstream ifs("input3.txt");
	// đọc số bộ test:
	ifs >> k;
	int i = 1;
	while (k--) { // duyệt và thực hiện chương trình với từng bộ test
		getArrayElements(ifs, arr1, m);
		getArrayElements(ifs, arr2, n);
		cout << "Test " << i++ << ": " << endl;
		insertAtMiddle(arr1, m, arr2, n);
		showArrayElements(arr1, m);
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

void insertAtMiddle(int* const arr1, int& m, 
	const int* const arr2, const int n) {
	// bước 1: dịch các phần tử nửa bên phải sang phải n vị trí
	for (int i = m + n - 1; i > m / 2 + n - 1; i--) {
		*(arr1 + i) = *(arr1 + i - n);
	}
	// bước 2: chèn mảng arr2 vào mảng arr1:
	for (int i = 0; i < n; i++) {
		*(arr1 + i + m / 2) = *(arr2 + i);
	}
	// cập nhật số phần tử của mảng arr1:
	m += n;
}