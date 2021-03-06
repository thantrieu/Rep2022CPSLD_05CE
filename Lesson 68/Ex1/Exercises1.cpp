/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <fstream>
using namespace std;

#define SIZE 100

// hàm ghi kết quả ra file
void writeArrayToFile(ofstream& ofs, const int* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		ofs << *(arr + i) << " ";
	}
	ofs << endl;
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
	int* arr;
	int n; // số phần tử thực tế
	ifstream reader("input1.txt");
	ofstream ofs("output1.txt");
	// đọc số bộ test:
	reader >> k;
	int i = 1;
	while (k--) { // duyệt và thực hiện chương trình với từng bộ test
		reader >> n;
		arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			reader >> arr[i];
		}
		ofs << "Test " << i++ << ": " << endl;
		writeArrayToFile(ofs, arr, n);
		sort(arr, n); // gọi hàm sắp xếp
		writeArrayToFile(ofs, arr, n);
		delete[] arr;
	}
	reader.close();
	ofs.close();
	return 0;
}