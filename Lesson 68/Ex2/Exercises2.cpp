/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <fstream>
using namespace std;
#define SIZE 100

// hàm hiển thị dữ liệu ra màn hình
void writeArrayToFile(ofstream& ofs, const double* const arr, const int size);
// hàm sắp xếp mảng theo thứ tự giảm dần
void sortDESC(double* const arr, const int size);
// hàm chèn x vào mảng:
void insertX(double* const arr, int& size, const double x);

int main() {
	int k; // số bộ test
	int n; // số phần tử thực tế
	double arr[SIZE];
	double x;
	ifstream ifs("input2.txt");
	ofstream ofs("output2.txt");
	// đọc số bộ test:
	if (ifs) {
		ifs >> k;
		int i = 1;
		while (k--) { // duyệt và thực hiện chương trình với từng bộ test
			ifs >> n >> x;
			for (int i = 0; i < n; i++) {
				ifs >> arr[i];
			}
			ofs << "Test " << i++ << ": " << endl;
			sortDESC(arr, n); // gọi hàm sắp xếp
			insertX(arr, n, x);
			writeArrayToFile(ofs, arr, n);
		}
	}
	else {
		cout << "Khong the mo file. vui long kiem tra lai\n";
	}
	ifs.close();
	ofs.close();

	return 0;
}

void writeArrayToFile(ofstream& ofs, const double* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		ofs << *(arr + i) << " ";
	}
	ofs << endl;
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