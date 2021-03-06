/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

void getArrayElements(int arr[], size_t& size, int& x);
int findOccurentOfX(const int arr[], size_t size, int x);

int main()
{
	int numbers[SIZE]; // khai báo mảng nguyên tối đa SIZE phần tử
	size_t n;
	int x;
	getArrayElements(numbers, n, x);
	int countX = findOccurentOfX(numbers, n, x);
	// kết quả:
	cout << countX << endl;

	return 0;
}

int findOccurentOfX(const int arr[], size_t size, int x) {
	// tìm số lần xuất hiện của x trong mảng:
	int countX = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == x) {
			countX++;
		}
	}
	return countX;
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
