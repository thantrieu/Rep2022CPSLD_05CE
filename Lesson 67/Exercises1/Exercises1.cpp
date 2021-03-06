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
void getArrayElements(int* const arr, int& size, ifstream& reader) {
	reader >> size;
	for (int i = 0; i < size; i++) {
		reader >> *(arr + i);
	}
}
// hàm hiển thị dữ liệu ra màn hình
void showArrayElements(const int* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
// hàm sắp xếp mảng theo thứ tự tăng dần
void sort(int* const arr, const int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (*(arr + j) < *(arr + j - 1)) {
				swap(*(arr + j), *(arr + j - 1));
			}
		}
	}
}

int main() {
	int k; // số bộ test
	int arr[SIZE];
	int n; // số phần tử thực tế
	ifstream reader("input1.txt");
	// đọc số bộ test:
	reader >> k;
	int i = 1;
	while (k--) { // duyệt và thực hiện chương trình với từng bộ test
		getArrayElements(arr, n, reader);
		cout << "Test " << i++ << ": " << endl;
		showArrayElements(arr, n);
		sort(arr, n); // gọi hàm sắp xếp
		showArrayElements(arr, n);
	}
	reader.close();
	return 0;
}