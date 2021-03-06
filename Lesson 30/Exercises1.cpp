/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

void getArrayElements(int arr[], size_t& size);
int sumOfArrayElements(int arr[], size_t size);

int main()
{
	int numbers[SIZE]; // khai báo mảng nguyên tối đa SIZE phần tử
	size_t n;
	getArrayElements(numbers, n);
	int sum = sumOfArrayElements(numbers, n);
	cout << sum << endl;

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
// hàm tính tổng các phần tử trong mảng
int sumOfArrayElements(int arr[], size_t size) {
	// tính tổng các phần tử trong mảng:
	int sum = 0; // khởi tạo biến tổng
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
