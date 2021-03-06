/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <functional>

using namespace std;
// hàm đọc dữ liệu đầu vào
void getInputData(double& a, double& b, double& c) {
	cout << "Nhap ba so a, b, c: ";
	cin >> a >> b >> c;
}
// hàm tính tổng
double sum(double a, double b, double c) {
	return a + b + c;
}
// hàm tính tích 
double mul(double a, double b, double c) {
	return a * b * c;
}
// hàm tính trung bình cộng
double average(double a, double b, double c) {
	return (a + b + c) / 3;
}
// hàm tính a - b - c
double sub(double a, double b, double c) {
	return a - b - c;
}
// hàm hiện kết quả
void showResult(double a, double b, double c,
	function<double(double, double, double)> calculate) {
	cout << calculate(a, b, c) << endl;
}

int main() {
	double a; 
	double b; 
	double c; 

	getInputData(a, b, c);
	if (a >= 0 && b >= 0 && c >= 0) {
		function<double(double, double, double)> calculate;
		calculate = sum;
		cout << "a + b + c = ";
		showResult(a, b, c, calculate);

		calculate = mul;
		cout << "a * b * c = ";
		showResult(a, b, c, calculate);

		calculate = average;
		cout << "TBC(a, b, c) = ";
		showResult(a, b, c, calculate);

		calculate = sub;
		cout << "a - b - c = ";
		showResult(a, b, c, calculate);
	}
	else {
		cout << "Nhap cac canh > 0" << endl;
	}

	return 0;
}