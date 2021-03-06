/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>

using namespace std;

#define SIZE 100

// hàm nhập dữ liệu vào
void getArrayElements(int* const arr, int& size);
// hàm tìm các phần tử chung của hai mảng arr1 và arr2
int findCommonElements(int* const arr1, const int m,
	const int* const arr2, const int n);

int main() {
	int k; // số bộ test
	int arr1[SIZE];
	int arr2[SIZE];
	int m, n; // số phần tử thực tế
	// đọc số bộ test:
	cin >> k;
	int i = 1;
	while (k--) { // duyệt và thực hiện chương trình với từng bộ test
		getArrayElements(arr1, m);
		getArrayElements(arr2, n);
		cout << "Test " << i++ << ": " << endl;
		auto resultNumber = findCommonElements(arr1, m, arr2, n);
		cout << resultNumber << endl;
	}

	return 0;
}

void getArrayElements(int* const arr, int& size) {
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> *(arr + i);
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
int findCommonElements(int* const arr1, const int m,
	const int* const arr2, const int n) {
	int count = 0; // khởi tạo biến đếm
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (*(arr1 + i) == *(arr2 + j)) {
				count++;
				cout << *(arr1 + i) << " ";
				break; // dừng việc tìm kiếm ở mảng thứ hai
			}
		}
	}
	cout << endl;
	return count;
}