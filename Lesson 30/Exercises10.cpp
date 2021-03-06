/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

void getArrayElements(int arr[], size_t& size, int& x);
void findResult(const int arr[], size_t size, int k);

int main()
{
	int numbers[SIZE]; // khai báo mảng nguyên tối đa SIZE phần tử
	int k;
	size_t size;
	getArrayElements(numbers, size, k);
	findResult(numbers, size, k);

	return 0;
}

// định nghĩa hàm nhập liệu các phần tử cho mảng
void getArrayElements(int arr[], size_t& size, int& x) {
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
		cout << "Nhap so nguyen x: ";
		cin >> x;
	}
}

void findResult(const int arr[], size_t size, int k) {
	if (k == 0) {
		cout << "K INVALID" << endl;
	}
	else {
		// tìm các phần tử chia hết cho k:
		int countK = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] % k == 0) {
				countK++;
			}
		}
		// kết quả:
		cout << countK << endl;
	}
}