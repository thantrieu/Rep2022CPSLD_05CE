// tính n!
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu tính n!
unsigned long long factorial(int n);

int main() {
	int n;
	cout << "Nhap n trong doan [0, 22]: ";
	cin >> n;
	if (n >= 0 && n <= 22) {
		cout << ULLONG_MAX << endl;
		unsigned long long f = factorial(n);
		cout << f << endl;
	}
	else {
		cout << "INVALID" << endl;
	}

	return 0;
}

// định nghĩa hàm
unsigned long long factorial(int n) {
	// n! = n * (n - 1)!
	if (n <= 1) {
		return 1; // trường hợp cơ sở
	}
	else { // bước đệ quy
		return n * factorial(n - 1);
	}
}