#include <iostream>
using namespace std;

/**
 * @author Branium Academy
 * @version 2022.02.16
 * @see https://braniumacademy.net
 */ 

#define PI 3.14

int main() {
    double r;
    cout << "Nhap ban kinh duong tron: ";
    cin >> r;
    if(r <= 0) {
        cout << "ERROR" << endl;
    } else {
        double perimeter = 2 * PI * r;
        double area = PI * r * r;
        cout << perimeter << " " << area << endl;
    }
}
