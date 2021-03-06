/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <vector>
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
    // hàm hiển thị các phần tử của vector
    template<class T> void showVectorElements(const vector<T>& v) {
        for (auto i = v.cbegin(); i != v.cend(); ++i)
        {
            cout << *i << " ";
        }
    }
}

int main() {
    vector<int> vectorInt;      // khai báo vector kiểu int
    vector<string> vectorString;// khai báo vector kiểu string
    
    // nhập vào các phần tử cho vector
    cout << "Nhap cac so nguyen int: \n";
    fillElements(vectorInt);
    cout << "Nhap cac doi tuong string: \n";
    fillElements(vectorString);

    // hiển thị các phần tử trong vector int
    cout << "Cac phan tu mang int: \n";
    showVectorElements(vectorInt);
    // hiển thị các phần tử trong vector string
    cout << "\nCac phan tu mang string: \n";
    showVectorElements(vectorString);

    return 0;
}
