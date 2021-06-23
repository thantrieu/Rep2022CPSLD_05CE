/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm> // để sử dụng hàm copy
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
}

int main() {
    list<int> listInt;      // khai báo list kiểu int
    list<string> listString;// khai báo list kiểu string
    // tạo đối tượng iterator để hiển thị dữ liệu ra màn hình
    ostream_iterator<int> ouputInt(cout, " "); // hiển thị giá trị int, cách nhau bởi dấu cách
    ostream_iterator<string> ouputString(cout, " "); // hiển thị giá trị string, cách nhau bởi dấu cách
    // nhập vào các phần tử cho list
    cout << "Nhap cac so nguyen int: \n";
    fillElements(listInt);
    cout << "Nhap cac doi tuong string: \n";
    fillElements(listString);

    // hiển thị các phần tử trong list int
    cout << "Cac phan tu mang int: \n";
    copy(listInt.begin(), listInt.end(), ouputInt);
    // hiển thị các phần tử trong list string
    cout << "\nCac phan tu mang string: \n";
    copy(listString.cbegin(), listString.cend(), ouputString);

    return 0;
}
