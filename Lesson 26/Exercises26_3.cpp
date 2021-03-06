// tính a^b với b >= 0
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu tính a^b
long long exponential(int a, int b);

int main() {
	int a, b;
	cin >> a >> b;

	if (b >= 0) {
		long long result = exponential(a, b);
		cout << result << endl;
	}
	else {
		cout << "INVALID" << endl;
	}

	return 0;
}

long long exponential(int a, int b) {
	//a^b = a * a^(b - 1)
	if (a == 0) {
		return 0; // trường hợp cơ sở
	}
	if (b == 0) {
		return 1; // trường hợp cơ sở
	}
	if (b == 1) {
		return a; // trường hợp cơ sở
	}
	else { // thực hiện bước đệ quy
		return a * exponential(a, b - 1);
	}
}