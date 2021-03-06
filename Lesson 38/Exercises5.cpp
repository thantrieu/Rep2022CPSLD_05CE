/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <cmath>

using namespace std;

#define SIZE 100

// hàm nhập dữ liệu vào
void getArrayElements(int* const arr, int& size, int& x);
// hàm hiển thị dữ liệu ra màn hình
void showArrayElements(const int* const arr, const int size);
// hàm xóa bỏ các phần tử trùng nhau trong mảng
void removeDuplicatedElements(int* const arr, int& n);
// hàm tìm giá trị gần x nhất
void findNearest(const int* const arr, const int size, const int x);

int main() {
	int k; // số bộ test
	int arr[SIZE];
	int n; // số phần tử thực tế
	int x;
	// đọc số bộ test:
	cin >> k;
	int i = 1;
	while (k--) { // duyệt và thực hiện chương trình với từng bộ test
		getArrayElements(arr, n, x);
		cout << "Test " << i++ << ": " << endl;
		removeDuplicatedElements(arr, n);
		showArrayElements(arr, n);
		findNearest(arr, n, x);
	}

	return 0;
}

void getArrayElements(int* const arr, int& size, int& x) {
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> *(arr + i);
	}
	cin >> x;
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

void findNearest(const int* const arr, const int size, const int x) {
	int findMinDistance(const int* const arr, const int size, const int x);
	int minDistance = findMinDistance(arr, size, x);
	for (int i = 0; i < size; i++) {
		if (abs(*(arr + i) - x) == minDistance) {
			cout << *(arr + i) << " ";
		}
	}
	cout << endl;
}

int findMinDistance(const int* const arr, const int size, const int x) {
	int distance = abs(*(arr)-x);
	for (int i = 1; i < size; i++) {
		int d = abs(*(arr + i) - x);
		if (d < distance) {
			distance = d;
		}
	}
	return distance;
}