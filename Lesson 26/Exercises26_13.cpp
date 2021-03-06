// Tính tổng các chữ số cấu thành của một số
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu tính tổng
double sum(long n);

int main() {
	long n;
	cout << "Nhap so nguyen n > 0: ";
	cin >> n;

	if (n > 0) {
		cout << sum(n) << endl;
	}
	else {
		cout << "INVALID" << endl;
	}

	return 0;
}

double sum(long n) {
	if (n == 1) {
		return n; // trường hợp cơ sở
	} // thực hiện bước đệ quy
	else {
		return (double)1 / n + sum(n - 1);
	}
}