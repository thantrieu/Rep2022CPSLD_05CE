/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <forward_list>
#include <iterator>
#include <algorithm> // để sử dụng hàm copy
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
}

int main() {
    forward_list<int> listInt;      // khai báo forward_list kiểu int
    forward_list<string> listString;// khai báo forward_list kiểu string
    // tạo đối tượng iterator để hiển thị dữ liệu ra màn hình
    ostream_iterator<int> ouputInt(cout, " "); // hiển thị giá trị int, cách nhau bởi dấu cách
    ostream_iterator<string> ouputString(cout, " "); // hiển thị giá trị string, cách nhau bởi dấu cách
    // nhập vào các phần tử cho forward_list
    cout << "Nhap cac so nguyen int: \n";
    fillElements(listInt);
    cout << "Nhap cac doi tuong string: \n";
    fillElements(listString);

    // hiển thị các phần tử trong forward_list int
    cout << "Cac phan tu mang int: \n";
    copy(listInt.begin(), listInt.end(), ouputInt);
    // hiển thị các phần tử trong forward_list string
    cout << "\nCac phan tu mang string: \n";
    copy(listString.cbegin(), listString.cend(), ouputString);

    return 0;
}
