/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <functional>

using namespace std;
#define SIZE 100

using ValidateFunction = function<bool(int, int)>;

// hàm định nghĩa quy tắc sắp xếp tăng dần
bool ascending(int a, int b) {
	return a > b;
}
// hàm định nghĩa quy tắc sắp xếp giảm dần
bool descending(int a, int b) {
	return a < b;
}
// hàm định nghĩa quy tắc sắp xếp số chẵn trước
bool evenFirst(int a, int b) {
	if ((a % 2 != 0 && b % 2 == 0)) {
		return true;
	}
	else {
		return false;
	}
}
// sắp xếp tăng dần, số chẵn trước
bool ascendingEvenFirst(int a, int b) {
	if ((a % 2 != 0 && b % 2 == 0) ||
		(a % 2 == 0 && b % 2 == 0 && a > b) ||
		(a % 2 != 0 && b % 2 != 0 && a > b)) {
		return true;
	}
	else {
		return false;
	}
}
// hàm định quy tắc sắp xếp số lẻ trước
bool oddFirst(int a, int b) {
	if (a % 2 == 0 && b % 2 != 0) {
		return true;
	}
	else {
		return false;
	}
}
// sắp xếp tăng dần, số lẻ trước
bool ascendingOddFirst(int a, int b) {
	if (a % 2 == 0 && b % 2 != 0 ||
		(a % 2 == 0 && b % 2 == 0 && a > b) ||
		(a % 2 != 0 && b % 2 != 0 && a > b)) {
		return true;
	}
	else {
		return false;
	}
}
// hàm định quy tắc sắp xếp số ng.tố trước
bool primeFirst(int a, int b) {
	bool isPrime(int);
	if ((!isPrime(a) && isPrime(b))) {
		return true;
	}
	else {
		return false;
	}
}
// sắp xếp tăng dần, số nguyên tố trước
bool ascendingPrimeFirst(int a, int b) {
	bool isPrime(int);
	if ((!isPrime(a) && isPrime(b)) || (isPrime(a) && isPrime(b) && a > b)
		|| (!isPrime(a) && !isPrime(b) && a > b)) {
		return true;
	}
	else {
		return false;
	}
}
// hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// hàm sắp xếp tăng:
void bubbleSort(int* const prices, const int size, ValidateFunction compare = ascending) {
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
	cout << "Nhap so phan tu mang: ";
	cin >> n;
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			cin >> *(arr + i);
		}
	}
}

int main()
{
	int prices[SIZE] = { 2, 3, 0, 1, 8, 4, 5, 9, 7, 6 };
	int n = 10;
	getArrayElements(prices, n);
	if (n > 0) {
		// khai báo con trỏ hàm
		function<bool(int, int)> funPtr;

		// gọi hàm sắp xếp tăng
		funPtr = ascending;
		bubbleSort(prices, n, funPtr);
		cout << "Sorted in ascending order: " << endl;
		showArrayElements(prices, n);

		// sắp xếp giảm dần
		funPtr = descending;
		bubbleSort(prices, n, funPtr);
		cout << "Sorted in descending order: " << endl;
		showArrayElements(prices, n);

		// sắp xếp số chẵn trước
		funPtr = evenFirst;
		bubbleSort(prices, n, funPtr);
		cout << "Sorted in order even numbers first: " << endl;
		showArrayElements(prices, n);

		// sắp xếp số lẻ trước
		funPtr = oddFirst;
		bubbleSort(prices, n, funPtr);
		cout << "Sorted in order odd numbers first: " << endl;
		showArrayElements(prices, n);

		// sắp xếp số nguyên tố trước
		funPtr = primeFirst;
		bubbleSort(prices, n, funPtr);
		cout << "Sorted in order primes first: " << endl;
		showArrayElements(prices, n);

		// sắp xếp tăng dần, số chẵn trước
		funPtr = ascendingEvenFirst;
		bubbleSort(prices, n, funPtr);
		cout << "Sorted in ascending order, even numbers first: " << endl;
		showArrayElements(prices, n);

		// sắp xếp tăng dần, số lẻ trước
		funPtr = ascendingOddFirst;
		bubbleSort(prices, n, funPtr);
		cout << "Sorted in ascending order, odd numbers first: " << endl;
		showArrayElements(prices, n);

		// sắp xếp tăng dần, số nguyên tố trước
		funPtr = ascendingPrimeFirst;
		bubbleSort(prices, n, funPtr);
		cout << "Sorted in ascending order, primes first: " << endl;
		showArrayElements(prices, n);
	}
	else {
		cout << "Nhap so phan tu cua mang > 0" << endl;
	}

	return 0;
}