// Hiển thị lên màn hình các số từ 0 đến n
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu
void listedNumbers(long long n, int start = 0);

int main() {
	long long n;
	cout << "Nhap so nguyen n: ";
	cin >> n;
	if (n < 0 || n > INT_MAX) {
		cout << "INVALID" << endl;
	}
	else {
		listedNumbers(n);
	}

	return 0;
}

void listedNumbers(long long n, int start) {
	cout << start << " ";
	if (start < n) {
		listedNumbers(n, start + 1);
	}
}