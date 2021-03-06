/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <list>
using namespace std;

namespace { // namespace vô danh
    // hàm nhập số phần tử và các phần tử của list
    template<class T> void fillElements(list<T>& list) {
        cout << "Nhap vao so luong phan tu cua mang: ";
        int size;
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Phan tu thu " << i << ": ";
            T t;
            cin >> t;
            list.push_back(t); // chèn phần tử vào sau vị trí phần tử cuối
        }
    }
    // hàm hiển thị các phần tử ra màn hình
    template<class T> void showListElements(const list<T>& list) {
        for (auto i = list.cbegin(); i != list.cend(); i++)
        {
            cout << *i << " "; // nếu hiển thị giá trị kiểu người dùng tự định nghĩa
        }                       // phải overload lại toán tử <<
        cout << endl;
    }
    // tìm giá trị max trong list
    template<class T> T findMax(const list<T>& list) {
        auto it = list.cbegin();
        T max = *it;
        while (it != list.cend()) {
            if (max < *it) {
                max = *it;
            }
            ++it;
        }
        return max;
    }
}

int main() {
    list<int> listInt;      // khai báo list kiểu int
    list<string> listString;// khai báo list kiểu string
    // nhập vào các phần tử cho list
    cout << "Nhap cac so nguyen int: \n";
    fillElements(listInt);
    cout << "Nhap cac doi tuong string: \n";
    fillElements(listString);

    // hiển thị các phần tử trong list int
    cout << "Cac phan tu mang int: \n";
    showListElements(listInt);
    // hiển thị các phần tử trong list string
    cout << "Cac phan tu mang string: \n";
    showListElements(listString);

    if (!listInt.empty()) {
        // tìm giá trị max
        int maxInt = findMax(listInt);
        cout << "Gia tri max trong list int: " << maxInt << endl;
    }
    if (!listString.empty()) {
        string maxString = findMax(listString);
        cout << "Gia tri max trong list string: " << maxString << endl;
    }

    return 0;
}
