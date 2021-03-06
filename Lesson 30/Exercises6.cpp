/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

// khai báo nguyên mẫu hàm:
void listedReverseNumbers(const int arr[], size_t n);
void getArrayElements(int arr[], size_t& size);
bool isReversed(int n);

int main()
{
	int numbers[SIZE]; // khai báo mảng nguyên tối đa SIZE phần tử
	size_t n;
	getArrayElements(numbers, n);
	// hiển thị các phần tử là số thuận nghịch trong mảng:
	listedReverseNumbers(numbers, n);

	return 0;
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

void listedReverseNumbers(const int arr[], size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		if (isReversed(arr[i])) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}

bool isReversed(int n) {
	n = (n < 0) ? -n : n; // bỏ dấu của n nếu n < 0
	if (n < 10) {
		return false;
	}
	int rev = 0;
	for (size_t i = n; i > 0; i /= 10)
	{
		rev = rev * 10 + i % 10;
	}
	return rev == n;
}