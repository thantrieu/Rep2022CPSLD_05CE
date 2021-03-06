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
        }                      // phải overload lại toán tử <<
        cout << endl;
    }
    // hàm xác định quy tắc sắp xếp
    template<class T> bool comparator(const T& a, const T& b) {
        return a > b;
    }
    // hàm sắp xếp các phần tử theo thứ tự giảm dần
    template<class T> void sortDESC(list<T>& list) {
        list.sort(comparator<T>); // nếu áp dụng với kiểu class/struct tự định nghĩa cần overload operator >
    }
    // hàm xóa bỏ các phần tử trùng nhau chỉ giữ lại 1 phần tử
    template<class T> int reduceDuplicatedElements(list<T> & list) {
        sortDESC(list);
        list.unique(); // hàm xóa phần tử trùng lặp
        return distance(list.cbegin(), list.cend());
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
    cout << "Cac phan tu mang int: ";
    showListElements(listInt);
    // hiển thị các phần tử trong list string
    cout << "Cac phan tu mang string: ";
    showListElements(listString);

    // sau khi xóa trùng lặp
    int remain = reduceDuplicatedElements(listInt);
    cout << "Cac phan tu trong danh sach int sau khi rut gon: ";
    showListElements(listInt);
    cout << "So phan tu con lai cua list: " << remain << endl;
    
    remain = reduceDuplicatedElements(listString);
    cout << "Cac phan tu trong danh sach string sau khi rut gon: ";
    showListElements(listString);
    cout << "So phan tu con lai cua list: " << remain << endl;

    return 0;
}
