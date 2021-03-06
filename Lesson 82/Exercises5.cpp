/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <deque>
using namespace std;

namespace { // namespace vô danh
    // hàm nhập số phần tử và các phần tử của deque
    template<class T> void fillElements(deque<T>& deque) {
        cout << "Nhap vao so luong phan tu cua deque: ";
        int size;
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Phan tu thu " << i << ": ";
            T t;
            cin >> t;
            deque.push_back(t); // chèn phần tử vào sau vị trí phần tử cuối
        }
    }
    // hàm hiển thị các phần tử ra màn hình
    template<class T> void showListElements(const deque<T>& deque) {
        for (auto i = deque.cbegin(); i != deque.cend(); i++)
        {
            cout << *i << " "; // nếu hiển thị giá trị kiểu người dùng tự định nghĩa
        }                       // phải overload lại toán tử <<
        cout << endl;
    }
    // tìm giá trị max trong deque
    template<class T> T findMax(const deque<T>& deque) {
        auto it = deque.cbegin();
        T max = *it;
        while (it != deque.cend()) {
            if (max < *it) {
                max = *it;
            }
            ++it;
        }
        return max;
    }
}

int main() {
    deque<int> dequeInt;      // khai báo deque kiểu int
    deque<string> dequeString;// khai báo deque kiểu string
    // nhập vào các phần tử cho deque
    cout << "Nhap cac so nguyen int: \n";
    fillElements(dequeInt);
    cout << "Nhap cac doi tuong string: \n";
    fillElements(dequeString);

    // hiển thị các phần tử trong deque int
    cout << "Cac phan tu deque int: \n";
    showListElements(dequeInt);
    // hiển thị các phần tử trong deque string
    cout << "Cac phan tu deque string: \n";
    showListElements(dequeString);

    if (!dequeInt.empty()) {
        // tìm giá trị max
        int maxInt = findMax(dequeInt);
        cout << "Gia tri max trong deque int: " << maxInt << endl;
    }
    if (!dequeString.empty()) {
        string maxString = findMax(dequeString);
        cout << "Gia tri max trong deque string: " << maxString << endl;
    }

    return 0;
}
