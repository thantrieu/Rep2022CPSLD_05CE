/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

void getArrayElements(int arr[], size_t& size);
bool checkSymmetrical(const int arr[], size_t size);

int main()
{
	int numbers[SIZE];
	size_t n;
	getArrayElements(numbers, n);
	// kiểm tra đối xứng:
	bool isSymmetrical = checkSymmetrical(numbers, n);
	cout << (isSymmetrical ? "YES" : "NO") << endl;

	return 0;
}

bool checkSymmetrical(const int arr[], size_t size) {
	bool isSymmetrical = true;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] != arr[size - 1 - i]) {
			isSymmetrical = false;
			break;
		}
	}
	return isSymmetrical;
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