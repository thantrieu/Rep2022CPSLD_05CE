/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

void getArrayElements(double arr[], size_t& size);
double sumOfArrayElements(double arr[], size_t size);

int main() {
	double realNumbers[SIZE];
	size_t n;
	getArrayElements(realNumbers, n);
	double sum = sumOfArrayElements(realNumbers, n);
	// kết quả:
	cout << sum / n;

	return 0;
}

// định nghĩa hàm nhập liệu các phần tử cho mảng
void getArrayElements(double arr[], size_t& size) {
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
double sumOfArrayElements(double arr[], size_t size) {
	// tính tổng các phần tử trong mảng:
	double sum = 0; // khởi tạo biến tổng
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}