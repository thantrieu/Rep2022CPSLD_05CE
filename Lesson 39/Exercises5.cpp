/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <functional>
#define SIZE 100

using namespace std;
// hàm đọc dữ liệu đầu vào
void getInputData(int* const arr, int& size) {
	cout << "Nhap so phan tu cua mang: ";
	cin >> size;
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			cin >> *(arr + i);
		}
	}
	else {
		cout << "Nhap so phan tu mang > 0" << endl;
	}
}
// hàm tìm giá trị lớn nhất
int findMax(const int* const arr, const int size) {
	auto max = *arr;
	for (int i = 1; i < size; i++) {
		if (*(arr + i) > max) {
			max = *(arr + i);
		}
	}
	return max;
}
// hàm tìm giá trị nhỏ nhất
int findMin(const int* const arr, const int size) {
	auto min = *arr;
	for (int i = 1; i < size; i++) {
		if (*(arr + i) < min) {
			min = *(arr + i);
		}
	}
	return min;
}
// hàm tìm giá trị lớn thứ hai
int findMax2(const int* const arr, const int size) {
	auto max2 = findMin(arr, size);
	auto max = findMax(arr, size);
	for (int i = 0; i < size; i++) {
		// nếu phần tử tại vị trí i lớn hơn max2 và khác max
		if (*(arr + i) > max2 && *(arr + i) != max) {
			max2 = *(arr + i);
		}
	}
	return max2;
}
// hàm tìm giá trị nhỏ thứ hai
int findMin2(const int* const arr, const int size) {
	auto min2 = findMax(arr, size);
	auto min = findMin(arr, size);
	for (int i = 0; i < size; i++) {
		// nếu phần tử tại vị trí i nhỏ hơn min2 và khác min
		if (*(arr + i) < min2 && *(arr + i) != min) {
			min2 = *(arr + i);
		}
	}
	return min2;
}
// hàm hiện kết quả
void showResult(const int* const arr, const int size,
	function<int(const int* const, const int)> findDesiredValue) {
	cout << findDesiredValue(arr, size) << endl;
}

int main() {
	int arr[SIZE];
	int size;
	getInputData(arr, size);
	if (size > 0) {
		function<int(const int* const, const int)> findDesiredValue;
		findDesiredValue = findMax;
		cout << "MAX = ";
		showResult(arr, size, findDesiredValue);

		findDesiredValue = findMin;
		cout << "MIN = ";
		showResult(arr, size, findDesiredValue);

		findDesiredValue = findMax2;
		cout << "MAX2 = ";
		showResult(arr, size, findDesiredValue);

		findDesiredValue = findMin2;
		cout << "MIN2 = ";
		showResult(arr, size, findDesiredValue);
	}

	return 0;
}