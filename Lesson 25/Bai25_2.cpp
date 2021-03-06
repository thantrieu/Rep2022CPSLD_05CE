/*
 * @author Branium Academy
 * @version 2021.02
 * @website braniumacademy.net
 */

#include <iostream>

using namespace std;

void getUserInput(double& length, double& width, double& height);
double surroundingArea(double length = 1.0, 
	double width = 1.0, double height = 1.0);
double totalArea(double length = 1.0,
	double width = 1.0, double height = 1.0);
double boxVolume(double length = 1.0,
	double width = 1.0, double height = 1.0);

int main() {
	double length, width, height;
	getUserInput(length, width, height);
	cout << "length = " << length << ", width = " 
		 << width << ", height = " << height << endl;
	cout << "=========================" << endl;
	// gọi hàm tính diện tích XQ với các bộ đối số khác nhau
	cout << "Dien tich XQ voi day du doi so: Sxq = " 
		 << surroundingArea(length, width, height) << endl;
	cout << "Dien tich XQ khuyet 1 doi so: Sxq = " 
		 << surroundingArea(length, width) << endl;
	cout << "Dien tich XQ khuyet 2 doi so: Sxq = " 
		 << surroundingArea(length) << endl;
	cout << "Dien tich XQ voi doi so mac dinh, Sxq = " 
		 << surroundingArea() << endl;
	cout << "=========================" << endl;
	// gọi hàm tính diện tích toàn phần với các bộ đối số khác nhau
	cout << "Dien tich TP voi day du doi so: S = "
		 << totalArea(length, width, height) << endl;
	cout << "Dien tich TP khuyet 1 doi so: S = "
		 << totalArea(length, width) << endl;
	cout << "Dien tich TP khuyet 2 doi so: S = " << totalArea(length) << endl;
	cout << "Dien tich TP voi doi so mac dinh, S = " << totalArea() << endl;
	cout << "=========================" << endl;
	// gọi hàm tính thể tích với các bộ đối số khác nhau
	cout << "The tich hinh hop voi day du doi so: V = "
		 << boxVolume(length, width, height) << endl;
	cout << "The tich hinh hop khuyet 1 doi so: V = "
		 << boxVolume(length, width) << endl;
	cout << "The tich hinh hop khuyet 2 doi so: V = "
		 << boxVolume(length) << endl;
	cout << "The tich hinh hop khuyet doi so: V = " << boxVolume() << endl;

	return 0;
}

void getUserInput(double& length, double& width, double& height) {
	cout << "Nhap vao chieu dai, rong, cao: ";
	cin >> length >> width >> height;
	// đảm bảo kích thước các chiều của hình hộp là hợp lệ
	length = length > 0 ? length : 1;
	width = width > 0 ? width : 1;
	height = height > 0 ? height : 1;
}
// diện tích xung quanh là diện tích các mặt bên trừ đáy trên và dưới
// theo quy ước diện tích hai đáy là 2(dài x rộng)
double surroundingArea(double length, double width, double height) {
	return 2 * height * (length + width);
}

double totalArea(double length,	double width, double height) {
	return 2 * (length * width + width * height + height * length);
}

double boxVolume(double length,	double width, double height) {
	return length * width * height;
}