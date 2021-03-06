/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool getInputFromKeyboard(int& n, int& b);
string convertFromBase10ToBaseB(int n, int b);

int main() {
	int n;
	int b;
	bool shouldContinue = getInputFromKeyboard(n, b);
	if (shouldContinue) {
		auto result = convertFromBase10ToBaseB(n, b);
		cout << result << endl;
	}
	return 0;
}

bool getInputFromKeyboard(int& n, int& b) {
	cout << "Nhap vao so nguyen duong n > 0, b [2, 32]: ";
	cin >> n >> b;
	if (n <= 0) {
		cout << "N INVALID" << endl;
		return false;
	}
	if (b < 2 || b > 32) {
		cout << "B INVALID" << endl;
		return false;
	}
	return true; // ok to continue
}

string convertFromBase10ToBaseB(int n, int b) {
	char map[] = { '0', '1', '2', '3', '4', '5', '6', '7', 
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
		'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 
		'S', 'T', 'U', 'V', 'X', 'Y', 'Z', 'W'};
	string result = "";
	while (n != 0) {
		result += map[n % b];
		n /= b;
	}
	reverse(result.begin(), result.end()); // đảo kết quả
	return result;
}