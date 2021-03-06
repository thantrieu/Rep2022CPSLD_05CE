/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
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
    // hàm tìm giá trị lớn nhất
    template<class T> T findMax(vector<T> v) {
        T max = v[0];
        for (size_t i = 1; i < v.size(); i++)
        {
            if (v[i] > max) {
                max = v[i];
            }
        }
        return max;
    }
    // hàm tìm giá trị nhỏ nhất
    template<class T> T findMin(vector<T> v) {
        T min = v[0];
        for (size_t i = 1; i < v.size(); i++)
        {
            if (v[i] < min) {
                min = v[i];
            }
        }
        return min;
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
    // tìm và hiển thị giá trị min trong vector
    int minInt = findMin(vectorInt);
    string minString = findMin(vectorString);
    cout << "Gia tri min trong vector kieu int: " << minInt << endl;
    cout << "Gia tri min trong vector kieu string: " << minString << endl;

    return 0;
}
