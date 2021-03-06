/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <functional>

using namespace std;

void getInputData(double& length, double& width) {
	cout << "Nhap chieu dai, chieu rong hinh chu nhat: ";
	cin >> length >> width;
}

double perimeter(double length, double width) {
	return 2 * (length + width);
}

double area(double length, double width) {
	return length * width;
}

void showResult(double a, double b, 
	function<double(double, double)> calculate) {
	cout << calculate(a, b) << endl;
}

int main() {
	double length; // chiều dài
	double width; // chiều rộng
	getInputData(length, width);
	if (length >= 0 && width >= 0) {
		function<double(double, double)> calculate;
		calculate = perimeter;
		cout << "Chu vi = ";
		showResult(length, width, calculate);
		calculate = area;
		cout << "Dien tich = ";
		showResult(length, width, calculate);
	}
	else {
		cout << "Nhap chieu dai, chieu rong > 0" << endl;
	}

	return 0;
}