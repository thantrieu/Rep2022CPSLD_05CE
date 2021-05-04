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
		// đọc vào các phần tử cho mảng:
		for (int i = 0; i < n; i++)
		{
			cin >> realNumbers[i];
		}
		// tính tổng:
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += realNumbers[i];
		}
		// kết quả:
		cout << sum / n;
	}
	else {
		cout << "N INVALID" << endl;
	}

	return 0;
} 