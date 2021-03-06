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
// hàm tìm các phần tử chung của hai mảng arr1 và arr2
int findCommonElements(ofstream& ofs, int* const arr1, const int m,
	const int* const arr2, const int n);
bool isExisted(int* const arr, int n, int x);

int main() {
	int k; // số bộ test
	int arr1[SIZE];
	int arr2[SIZE];
	int m, n; // số phần tử thực tế
	ifstream ifs("input4.txt");
	ofstream ofs("output4.txt");
	// đọc số bộ test:
	ifs >> k;
	int i = 1;
	while (k--) { // duyệt và thực hiện chương trình với từng bộ test
		getArrayElements(ifs, arr1, m);
		getArrayElements(ifs, arr2, n);
		ofs << "Test " << i++ << ": " << endl;
		auto resultNumber = findCommonElements(ofs, arr1, m, arr2, n);
		ofs << resultNumber << endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}

void getArrayElements(ifstream& ifs, int* const arr, int& size) {
	ifs >> size;
	for (int i = 0; i < size; i++) {
		ifs >> *(arr + i);
	}
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
/*	Ý tưởng: duyệt mảng thứ nhất xét từng phần tử xem nó
	có xuất hiện trong mảng thứ hai hay không.
	Nếu có thì tăng biến đếm và in ra giá trị của phần tử đó
*/
int findCommonElements(ofstream& ofs, int* const arr1, const int m,
	const int* const arr2, const int n) {
	int count = 0; // khởi tạo biến đếm
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// nếu phần tử này chưa xuất hiện trước đó thì hiển thị ra
			if (*(arr1 + i) == *(arr2 + j) && !isExisted(arr1, i, *(arr1 + i))) {
				count++;
				ofs << *(arr1 + i) << " ";
				break; // dừng việc tìm kiếm ở mảng thứ hai
			}
		}
	}
	ofs << endl;
	return count;
}

bool isExisted(int* const arr, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (*(arr + i) == x) {
			return true;
		}
	}
	return false;
}