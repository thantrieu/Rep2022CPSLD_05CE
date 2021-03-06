// Hiển thị lên màn hình các số chẵn và lẻ trong đoạn [a, b]
/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

//hàm nguyên mẫu
void oddNumbers(long long a, long long b);
void evenNumbers(long long a, long long b);

int main() {
	long long a, b;
	cout << "Nhap so 2 nguyen a < b: ";
	cin >> a >> b;
	if (a < INT_MIN || a > INT_MAX 
		|| b < INT_MIN || b > INT_MAX || a >= b) {
		cout << "INVALID" << endl;
	}
	else {
		evenNumbers(a, b);
		cout << endl;
		oddNumbers(a, b);
	}

	return 0;
}

void evenNumbers(long long a, long long b) {
	if (a % 2 == 0) {
		cout << a << " ";
	}
	if (a < b) {
		evenNumbers(a + 1, b);
	}
}

void oddNumbers(long long a, long long b) {
	if (a % 2 != 0) {
		cout << a << " ";
	}
	if (a < b) {
		oddNumbers(a + 1, b);
	}
}