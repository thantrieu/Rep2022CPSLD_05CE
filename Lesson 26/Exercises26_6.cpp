// Đếm số lượng các chữ số cấu thành của một số
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu đếm các chữ số của 1 số
int numberOfDigits(long long n);

int main() {
	long long n;
	cout << "Nhap so nguyen n: ";
	cin >> n;

	if (n < 0) {
		n = -n;
	}
	int result = numberOfDigits(n);
	cout << result << endl;

	return 0;
}

int numberOfDigits(long long n) {
	if (n < 10) {
		return 1; // trường hợp cơ sở
	}
	else { // bước đệ quy
		return 1 + numberOfDigits(n / 10);
	}
}