/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

int main() {
	double realNumbers[SIZE];
	int n;
	cout << "Nhap vao so phan tu cua mang: ";
	cin >> n;
	if (n > 0) {
		size_t size = n;
		// đọc vào các phần tử cho mảng:
		for (size_t i = 0; i < size; i++)
		{
			cin >> realNumbers[i];
		}
		// tính tổng:
		double sum = 0;
		int oddIndexElements = ceil(1.0 * n / 2);
		for (size_t i = 0; i < size; i += 2)
		{
			sum += realNumbers[i];
		}
		// kết quả: 
		cout << sum / oddIndexElements;
	}
	else {
		cout << "N INVALID" << endl;
	}

	return 0;
}