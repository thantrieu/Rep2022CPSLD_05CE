/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <fstream>
using namespace std;

#define SIZE 100

// hàm nhập dữ liệu vào. ifstream truyền tham số tham chiếu để cho phép update
// con trỏ file
void getArrayElements(ifstream& ifs, double* const arr, int& size, double &x);
// hàm hiển thị dữ liệu ra màn hình
void showArrayElements(const double* const arr, const int size);
// hàm sắp xếp mảng theo thứ tự giảm dần
void sortDESC(double* const arr, const int size);
// hàm chèn x vào mảng:
void insertX(double* const arr, int& size, const double x);

int main() {
	int k; // số bộ test
	double arr[SIZE];
	int n; // số phần tử thực tế
	double x;
	ifstream ifs("input2.txt");
	// đọc số bộ test:
	ifs >> k;
	int i = 1;
	while (k--) { // duyệt và thực hiện chương trình với từng bộ test
		getArrayElements(ifs, arr, n, x);
		cout << "Test " << i++ << ": " << endl;
		sortDESC(arr, n); // gọi hàm sắp xếp
		insertX(arr, n, x);
		showArrayElements(arr, n);
	}
	ifs.close();
	return 0;
}

void getArrayElements(ifstream& ifs, double* const arr, int& size, double& x) {
	ifs >> size >> x;
	for (int i = 0; i < size; i++) {
		ifs >> *(arr + i);
	}
}

void showArrayElements(const double* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

void sortDESC(double* const arr, const int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (*(arr + j) > *(arr + j - 1)) {
				swap(*(arr + j), *(arr + j - 1));
			}
		}
	}
}

void insertX(double* const arr, int& size, const double x) {
	for (int i = 0; i < size; i++) {
		if (*(arr + i) < x) {
			for (int j = size; j > i; j--) {
				*(arr + j) = *(arr + j - 1);
			}
			*(arr + i) = x;
			size++;
			break;
		}
	}
}