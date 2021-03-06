// tính a^b với b >= 0
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu tìm ước chung lớn nhất
long gcd(long a, long b);

int main() {
	long a, b;
	cout << "Nhap so nguyen a, b > 0: ";
	cin >> a >> b;

	if (a > 0 && b > 0) {
		long result = gcd(a, b);
		cout << result << endl;
	}
	else {
		cout << "INVALID" << endl;
	}

	return 0;
}

long gcd(long a, long b) {
	if (a == b) {
		return a; // trường hợp cơ sở
	} // thực hiện bước đệ quy
	else if (a > b) {
		return gcd(a - b, b);
	}
	else {
		return gcd(a, b - a);
	}
}