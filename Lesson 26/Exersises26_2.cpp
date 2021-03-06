// Tìm số Fibonacci thứ n, n <= 93
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu tính Fibonacci
unsigned long long fibonacci(int n);

int main() {
	int n;
	cout << "Nhap n trong doan [0, 93]: " << endl;
	cin >> n;
	if (n >= 0 && n <= 93) {
		unsigned long long fn = fibonacci(n);
		cout << fn << endl;
	}
	else {
		cout << "INVALID" << endl;
	}

	return 0;
}

unsigned long long fibonacci(int n) {
	//fn = fn-1 + fn-2
	if (n < 2) {
		return n; // trường hợp cơ sở
	}
	else { // thực hiện bước đệ quy
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}