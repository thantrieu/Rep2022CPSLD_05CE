/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#define _USE_MATH_DEFINES
#include <iostream>

using namespace std;
// khai báo hàm nguyên mẫu
double getRadius();
double sphereArea(double radius = 1.0);
double sphereVolume(double radius = 1.0);

int main() {
	double radius;
	radius = getRadius();
	cout << "Ban kinh r = " << radius << endl;
	cout << "==========================" << endl;
	// tính diện tích bề mặt với các bộ tham số khác nhau
	cout << "Dien tich mat cau voi doi so r, S = " << sphereArea(radius) << endl;
	cout << "Dien tich mat cau khong doi so, S = " << sphereArea() << endl;
	cout << "==========================" << endl;
	// tính thể tích với các bộ tham số khác nhau
	cout << "The tich mat cau voi doi so r, V = " << sphereVolume(radius) << endl;
	cout << "The tich mat cau khong doi so, V = " << sphereVolume() << endl;
	cout << "==========================" << endl;
	// diện tích và thể tích của trái đất
	double earthRadius = 6371;
	cout << "Dien tich Earth = " << sphereArea(earthRadius)  << "km2" << endl;
	cout << "The tich Earth = " << sphereVolume(earthRadius)  << "km3" << endl;

	return 0;
}

double getRadius() {
	double radius;
	cout << "Nhap vao ban kinh hinh cau: ";
	cin >> radius;
	return radius;
}
// diện tích mặt cầu
double sphereArea(double radius) {
	return 4 * M_PI * radius * radius;
}
// thể tích khối cầu
double sphereVolume(double radius) {
	return 4 * M_PI * pow(radius, 3) / 3;
}