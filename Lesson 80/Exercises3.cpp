/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <forward_list>
using namespace std;

namespace { // namespace vô danh
    // hàm nhập số phần tử và các phần tử của forward_list
    template<class T> void fillElements(forward_list<T>& list) {
        cout << "Nhap vao so luong phan tu cua mang: ";
        int size;
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Phan tu thu " << i << ": ";
            T t;
            cin >> t;
            list.push_front(t);
        }
    }
    // hàm hiển thị các phần tử ra màn hình
    template<class T> void showListElements(const forward_list<T>& list) {
        for (auto i = list.cbegin(); i != list.cend(); i++)
        {
            cout << *i << " "; // nếu hiển thị giá trị kiểu người dùng tự định nghĩa
        }                       // phải overload lại toán tử <<
        cout << endl;
    }
}

int main() {
    forward_list<int> listInt;      // khai báo forward_list kiểu int
    forward_list<string> listString;// khai báo forward_list kiểu string
    // nhập vào các phần tử cho forward_list
    cout << "Nhap cac so nguyen int: \n";
    fillElements(listInt);
    cout << "Nhap cac doi tuong string: \n";
    fillElements(listString);

    // hiển thị các phần tử trong forward_list int
    cout << "Cac phan tu mang int: \n";
    showListElements(listInt);
    // hiển thị các phần tử trong forward_list string
    cout << "Cac phan tu mang string: \n";
    showListElements(listString);
    return 0;
}
