/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm> // để sử dụng hàm copy
using namespace std;

namespace { // namespace vô danh
    // hàm nhập số phần tử và các phần tử của deque
    template<class T> void fillElements(deque<T>& deque) {
        cout << "Nhap vao so luong phan tu: ";
        int size;
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Phan tu thu " << i << ": ";
            T t;
            cin >> t;
            deque.push_back(t); // chèn phần tử vào sau vị trí phần tử cuối
        }
    }
}

int main() {
    deque<int> dequeInt;      // khai báo deque kiểu int
    deque<string> dequeString;// khai báo deque kiểu string
    // tạo đối tượng iterator để hiển thị dữ liệu ra màn hình
    ostream_iterator<int> ouputInt(cout, " "); // hiển thị giá trị int, cách nhau bởi dấu cách
    ostream_iterator<string> ouputString(cout, " "); // hiển thị giá trị string, cách nhau bởi dấu cách
    // nhập vào các phần tử cho deque
    cout << "Nhap cac so nguyen int: \n";
    fillElements(dequeInt);
    cout << "Nhap cac doi tuong string: \n";
    fillElements(dequeString);

    // hiển thị các phần tử trong deque int
    cout << "Cac phan tu deque int: \n";
    copy(dequeInt.begin(), dequeInt.end(), ouputInt);
    // hiển thị các phần tử trong deque string
    cout << "\nCac phan tu deque string: \n";
    copy(dequeString.cbegin(), dequeString.cend(), ouputString);

    return 0;
}
