/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> // để sử dụng hàm copy
    using namespace std;

namespace { // namespace vô danh
    // hàm nhập số phần tử và các phần tử của vector
    template<class T> void fillElements(vector<T>& v) {
        cout << "Nhap vao so luong phan tu cua mang: ";
        int size;
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Phan tu thu " << i << ": ";
            T t;
            cin >> t;
            v.push_back(t);
        }
    }
}

int main() {
    vector<int> vectorInt;      // khai báo vector kiểu int
    vector<string> vectorString;// khai báo vector kiểu string
    // tạo đối tượng iterator để hiển thị dữ liệu ra màn hình
    ostream_iterator<int> ouputInt(cout, " "); // hiển thị giá trị int, cách nhau bởi dấu cách
    ostream_iterator<string> ouputString(cout, " "); // hiển thị giá trị string, cách nhau bởi dấu cách
    // nhập vào các phần tử cho vector
    cout << "Nhap cac so nguyen int: \n";
    fillElements(vectorInt);
    cout << "Nhap cac doi tuong string: \n";
    fillElements(vectorString);

    // hiển thị các phần tử trong vector int
    cout << "Cac phan tu mang int: \n";
    copy(vectorInt.begin(), vectorInt.end(), ouputInt);
    // hiển thị các phần tử trong vector string
    cout << "\nCac phan tu mang string: \n";
    copy(vectorString.cbegin(), vectorString.cend(), ouputString);

    return 0;
}
