/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.04
 *
 */
#include <iostream>

using namespace std;

void getInput(double*, double*, double*);
void volume(double*, double*, double*, double*);
void surroundingArea(double*, double*, double*, double*);
void totalArea(double*, double*, double*, double*);
void showResult(double*);

int main() {
	double length;
	double width;
	double height;
	getInput(&length, &width, &height);
	if (length > 0 && width > 0 && height > 0) {
		auto sArea = 0.0;
		auto tArea = 0.0;
		auto v = 0.0;
		surroundingArea(&length, &width, &height, &sArea);
		totalArea(&length, &width, &height, &tArea);
		volume(&length, &width, &height, &v);
		
		// hiển thị kết quả:
		cout << "Dien tich xung quanh: ";
		showResult(&sArea);
		cout << "Dien tich toan phan: ";
		showResult(&tArea);
		cout << "The tich: ";
		showResult(&v);
	}
	else {
		cout << "Cac canh hinh hop khong hop le" << endl;
	}

	return 0;
}

void getInput(double* length, double* width, double* height) {
	cout << "Nhap vao ba canh hinh hop: " << endl;
	cin >> *length >> *width >> *height;
}

void volume(double* length, double* width, double* height, double* volume) {
	*volume = (*length) * (*width) * (*height);
}
// diện tích xung quanh không tính 2 đáy(dài x rộng)
void surroundingArea(double* length, double* width, double* height, double* area) {
	*area = 2 * (*length * *height + *width * *height);
}
// diện tích toàn phần tính cả hai đáy
void totalArea(double* length, double* width, double* height, double* area) {
	*area = 2 * (*length * *height + *width * *height + *width * *length);
}

void showResult(double* result) {
	cout << *result << endl;
}