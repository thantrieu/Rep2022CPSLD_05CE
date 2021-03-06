/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

namespace { // namespace vô danh
    // hàm nhập số phần tử và các phần tử của deque
    template<class T> void fillElements(deque<T>& deque) {
        cout << "Nhap vao so luong phan tu cua deque: ";
        int size;
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Phan tu thu " << i << ": ";
            T t;
            cin >> t;
            deque.push_back(t); // chèn phần tử vào sau vị trí phần tử cuối
        }
    }
    // hàm hiển thị các phần tử ra màn hình
    template<class T> void showListElements(const deque<T>& deque) {
        for (auto i = deque.cbegin(); i != deque.cend(); i++)
        {
            cout << *i << " "; // nếu hiển thị giá trị kiểu người dùng tự định nghĩa
        }                      // phải overload lại toán tử <<
        cout << endl;
    }
    // hàm sắp xếp các phần tử theo thứ tự tăng dần
    template<class T> void sortASC(deque<T>& deque) {
        sort(deque.begin(), deque.end()); // nếu áp dụng với kiểu class/struct tự định nghĩa cần overload operator <
    }
}

int main() {
    deque<int> dequeInt;      // khai báo deque kiểu int
    deque<string> dequeString;// khai báo deque kiểu string
    // nhập vào các phần tử cho deque
    cout << "Nhap cac so nguyen int: \n";
    fillElements(dequeInt);
    cout << "Nhap cac doi tuong string: \n";
    fillElements(dequeString);

    // hiển thị các phần tử trong deque int
    cout << "Cac phan tu deque int: ";
    showListElements(dequeInt);
    // hiển thị các phần tử trong deque string
    cout << "Cac phan tu deque string: ";
    showListElements(dequeString);

    // sau khi sắp xếp
    sortASC(dequeInt);
    sortASC(dequeString);
    cout << "Cac phan tu trong deque int sau khi sap xep: ";
    showListElements(dequeInt);
    cout << "Cac phan tu trong deque string sau khi sap xep: ";
    showListElements(dequeString);

    return 0;
}
