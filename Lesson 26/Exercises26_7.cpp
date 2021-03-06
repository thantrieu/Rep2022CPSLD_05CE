// Tính tổng từ 1 - n với n > 1 nhập vào từ bàn phím
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu
int sumFrom1ToN(int n);

int main() {
	int n;
	cout << "Nhap so nguyen n: ";
	cin >> n;

	if (n < 0) {
		cout << "INVALID" << endl;
	}
	else {
		int result = sumFrom1ToN(n);
		cout << result << endl;
	}

	return 0;
}

int sumFrom1ToN(int n) {
	if (n == 1) {
		return 1; // trường hợp cơ sở
	}
	else { // bước đệ quy
		return n + sumFrom1ToN(n - 1);
	}
}