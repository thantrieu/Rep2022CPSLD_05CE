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
            auto it = list.cbefore_begin();
            auto beforeIt = it;
            while (it != list.cend()) // tìm vị trí cuối của danh sách
            {
                beforeIt = it;
                ++it;
            }
            list.insert_after(beforeIt, t); // chèn phần tử vào sau vị trí phần tử cuối
        }
    }
    // hàm hiển thị các phần tử ra màn hình
    template<class T> void showListElements(const forward_list<T>& list) {
        for (auto i = list.cbegin(); i != list.cend(); i++)
        {
            cout << *i << " "; // nếu hiển thị giá trị kiểu người dùng tự định nghĩa
        }                      // phải overload lại toán tử <<
        cout << endl;
    }
    // hàm xác định quy tắc sắp xếp
    template<class T> bool comparator(const T& a, const T& b) {
        return a > b;
    }
    // hàm sắp xếp các phần tử theo thứ tự giảm dần
    template<class T> void sortDESC(forward_list<T>& list) {
        list.sort(comparator<T>); // nếu áp dụng với kiểu class/struct tự định nghĩa cần overload operator >
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
    cout << "Cac phan tu mang int: ";
    listInt.reverse(); // đảo ngược các phần tử trong danh sách
    showListElements(listInt);
    // hiển thị các phần tử trong forward_list string
    cout << "Cac phan tu mang string: ";
    showListElements(listString);

    // sau khi sắp xếp
    sortDESC(listInt);
    sortDESC(listString);
    cout << "Cac phan tu trong danh sach int sau khi sap xep: ";
    showListElements(listInt);
    cout << "Cac phan tu trong danh sach string sau khi sap xep: ";
    showListElements(listString);

    return 0;
}
