// Tính tổng các chữ số cấu thành của một số
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu tính tổng các chữ số của 1 số
int sumOfDigits(long long n);

int main() {
	long long n;
	cout << "Nhap so nguyen n: ";
	cin >> n;

	if (n < 0) {
		n = -n;
	}
	int result = sumOfDigits(n);
	cout << result << endl;

	return 0;
}

int sumOfDigits(long long n) {
	if (n < 10) {
		return n; // trường hợp cơ sở
	}
	else { // bước đệ quy
		return n % 10 + sumOfDigits(n / 10);
	}
}