/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <vector>
#include <array>
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
    // hàm tính trung bình cộng các phần tử
    template<class T> double average(const vector<T>& v) {
        T sum = 0;
        for (size_t i = 0; i < v.size(); i++)
        {
            sum += v.at(i);
        }
        return 1.0 * sum / v.size();
    }
 
}


int main() {
    const int n = 10;
    array<int, n> intArray = {1, 2, 4, 3, 6, 5, 7, 8, 9, 10};
    array<double, n> doubleArray = {1.65, 2.3, 54.56, 3.6, 6, 5.8, 7, 8.99, 9.53, 0.73};
    array<float, n> floatArray = {1.4f, 23.58f, 4.57f, 3.3f, 6.74f, 5.25f, 25.7f, 8.39f, 9.98f, 0.97f};
    
    vector<int> vectorInt(intArray.cbegin(), intArray.cend());
    vector<double> vectorDouble(doubleArray.cbegin(), doubleArray.cend());
    vector<float> vectorFloat(floatArray.cbegin(), floatArray.cend());
    
    cout << "TBC cac phan tu vector int = " << average(vectorInt) << endl;
    cout << "TBC cac phan tu vector float = " << average(vectorFloat) << endl;
    cout << "TBC cac phan tu vector double = " << average(vectorDouble) << endl;

    return 0;
}

