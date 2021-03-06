/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm> // để sử dụng hàm copy
using namespace std;

namespace { // namespace vô danh
    // lớp template định ra quy tắc thiết lập trật tự các phần tử trong set
    template<class T> struct DescStruct {
        bool operator() (T const& a, T const& b) const {
            return a > b;
        }
    };
    // hàm nhập số phần tử và các phần tử của set
    template<class T> void fillElements(set<T, DescStruct<T>>& set) {
        cout << "Nhap vao so luong phan tu: ";
        int size;
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Phan tu thu " << i << ": ";
            T t;
            cin >> t;
            set.insert(t);
        }
    }
}

int main() {
    set<int, DescStruct<int>> setInt;      // khai báo set kiểu int
    // tạo đối tượng iterator để hiển thị dữ liệu ra màn hình
    ostream_iterator<int> ouputInt(cout, " "); // hiển thị giá trị int, cách nhau bởi dấu cách
    // nhập vào các phần tử cho set
    cout << "Nhap cac so nguyen int: \n";
    fillElements(setInt);

    // hiển thị các phần tử trong set int
    cout << "Cac phan tu set int: \n";
    copy(setInt.begin(), setInt.end(), ouputInt);

    return 0;
}
