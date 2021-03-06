/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

// khai báo nguyên mẫu hàm:
void listedPrimeNumbers(const int arr[], size_t n);
void getArrayElements(int arr[], size_t& size);
bool isPrime(int n);

int main()
{
	int numbers[SIZE]; // khai báo mảng nguyên tối đa SIZE phần tử
	size_t n;
	getArrayElements(numbers, n);
	// liệt kê các số nguyên tố:
	listedPrimeNumbers(numbers, n);

	return 0;
}

void listedPrimeNumbers(const int arr[], size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		if (isPrime(arr[i])) {
			cout << "(" << i << ", " << arr[i] << ") ";
		}
	}
}

// định nghĩa hàm nhập liệu các phần tử cho mảng
void getArrayElements(int arr[], size_t& size) {
	int n;
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	if (n <= 0) {
		cout << "N INVALID" << endl;
	}
	else {
		size = n;
		// đọc vào các phần tử của mảng:
		cout << "Nhap " << size << " phan tu cua mang: " << endl;
		for (size_t i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}
}

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	int upperBound = sqrt(n);
	for (size_t i = 2; i <= upperBound; i++)
	{
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}