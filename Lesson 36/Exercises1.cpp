/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.04
 *
 */
#include <iostream>

using namespace std;

// hàm nguyên mẫu:
void getInput(double*, double*, double*);
void perimeter(double*, double*, double*, double*);
void area(double*, double*, double*, double*);
void showResult(double*);

int main()
{
    double a;
    double b;
    double c;
    double triangleArea;
    double trianglePerimeter;
    getInput(&a, &b, &c);
    if (a + b > c && b + c > a && c + a > b) {
        perimeter(&a, &b, &c, &trianglePerimeter);
        area(&a, &b, &c, &triangleArea);
        cout << "Chu vi: ";
        showResult(&trianglePerimeter);
        cout << "Dien tich: ";
        showResult(&triangleArea);
    }
    else {
        cout << "Ba canh tam giac khong hop le" << endl;
    }
}
// nhập dữ liệu từ bàn phím
void getInput(double* a, double* b, double* c) {
    cout << "Nhap vao ba canh tam giac: ";
    cin >> *a >> *b >> *c;
}
// tính chu vi
void perimeter(double* a, double* b, double* c, double* result) {
    *result = (*a) + (*b) + (*c);
}
// tính diện tích
void area(double* a, double* b, double* c, double* result) {
    // sử dụng công thức heron:
    auto p = 0.5 * (*a + *b + *c);
    *result = sqrt(p * (p - *a) * (p - *b) * (p - *c));
}
// hiển thị kết quả
void showResult(double* result) {
    cout << *result << endl;
}
