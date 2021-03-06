// Kiểm tra số nguyên tố
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu
bool isPrime(int n, int i = 2);

int main() {
	int n;
	cout << "Nhap so nguyen n: ";
	cin >> n;

	cout << (isPrime(n) ? "YES" : "NO") << endl;

	return 0;
}

bool isPrime(int n, int i) {
	if (n <= 2) {
		return n == 2 ? true : false;
	}
	if (n % i == 0) {
		return false;
	}
	if (i * i > n) {
		return true;
	}
	return isPrime(n, i + 1);
}