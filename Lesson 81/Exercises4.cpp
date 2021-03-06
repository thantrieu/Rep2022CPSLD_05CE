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
            list.push_back(t);
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
    listInt.reverse(); // đảo ngược các phần tử trong danh sách
    showListElements(listInt);
    // hiển thị các phần tử trong list string
    cout << "Cac phan tu mang string: \n";
    listString.reverse();
    showListElements(listString);
    return 0;
}
