/**
 * @author Branium Academy
 * @version 2022.02.16
 * @see https://braniumacademy.net
 */ 

#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    cout << "Nhap hai so nguyen a, b: ";
    cin >> a >> b;
    // kiem tra va in ket qua
    int dif = a - b;
    if(dif == 0) {
        cout << "a bang b" << endl;
    } else {
        if(dif < 0) {
            dif = -dif;
        }
        cout << "a khac b " << dif << " don vi" << endl;
    }
    cout << endl;
}
