/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <functional>

using namespace std;

using ValidateFunction = function<bool(int, int)>;

// sắp xếp tăng dần, số chẵn trước
bool ascendingEvenFirst(int a, int b) {
	if ((a % 2 != 0 && b % 2 == 0) ||
		(a % 2 == 0 && b % 2 == 0 && a > b) ||
		(a % 2 != 0 && b % 2 != 0 && a < b)) {
		return true;
	}
	else {
		return false;
	}
}

// sắp xếp giảm dần, số lẻ trước
bool ascendingOddFirst(int a, int b) {
	if (a % 2 == 0 && b % 2 != 0 ||
		(a % 2 == 0 && b % 2 == 0 && a > b) ||
		(a % 2 != 0 && b % 2 != 0 && a < b)) {
		return true;
	}
	else {
		return false;
	}
}

// hàm sắp xếp tăng:
void bubbleSort(int* const prices, const int size, ValidateFunction compare) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			// nếu thỏa mãn điều kiện sắp xếp
			if (compare(prices[j - 1], prices[j])) {
				// đổi chỗ 2 phần tử
				swap(prices[j], prices[j - 1]);
			}
		}
	}
}

// hàm hiển thị kết quả
void showArrayElements(const int* const prices, const int size) {
	for (int i = 0; i < size; i++) {
		cout << *(prices + i) << " ";
	}
	cout << endl;
}
// hàm nhập dữ liệu
void getArrayElements(int* const arr, int& n) {
	for (int i = 0; i < n; i++) {
		cin >> *(arr + i);
	}
}

int main()
{
	// mảng cấp phát động
	int n = 10;
	cout << "Nhap so phan tu mang: ";
	cin >> n;
	if (n > 0) {
		int* prices = new int[n]();
		getArrayElements(prices, n);
		// khai báo con trỏ hàm
		function<bool(int, int)> funPtr;
		// sắp xếp tăng dần, số chẵn trước
		funPtr = ascendingEvenFirst;
		bubbleSort(prices, n, funPtr);
		cout << "Sap xep so chan truoc, tang dan: " << endl;
		showArrayElements(prices, n);

		// sắp xếp tăng dần, số lẻ trước
		funPtr = ascendingOddFirst;
		bubbleSort(prices, n, funPtr);
		cout << "Sap xep so le truoc, giam dan: " << endl;
		showArrayElements(prices, n);

		// thu hồi bộ nhớ chủ động trước khi kết thúc chương trình
		delete[] prices;
	}
	else {
		cout << "Nhap so phan tu cua mang > 0" << endl;
	}

	return 0;
}