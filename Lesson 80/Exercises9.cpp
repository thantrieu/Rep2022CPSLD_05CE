/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include <iostream>
#include <forward_list>
#include <iterator>
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
            auto it = list.cbefore_begin();
            auto beforeIt = it;
            while (it != list.cend()) // tìm vị trí cuối của danh sách
            {
                beforeIt = it;
                ++it;
            }
            list.insert_after(beforeIt, t); // chèn phần tử vào sau vị trí phần tử cuối
        }
    }
    // hàm hiển thị các phần tử ra màn hình
    template<class T> void showListElements(const forward_list<T>& list) {
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
    template<class T> void sortDESC(forward_list<T>& list) {
        list.sort(comparator<T>); // nếu áp dụng với kiểu class/struct tự định nghĩa cần overload operator >
    }
    // hàm xóa bỏ các phần tử trùng nhau chỉ giữ lại 1 phần tử
    template<class T> void reduceDuplicatedElements(forward_list<T>& list) {
        sortDESC(list);
        list.unique(); // hàm xóa phần tử trùng lặp
    }
    // hàm tìm giá trị lớn thứ k trong ds
    template<class T> void findMaxKth(forward_list<T> list, int k) {
        int size = distance(list.cbegin(), list.cend());
        if (k <= 0 || k > size) {
            cout << "Khong ton tai phan tu lon thu " << k << endl;
        }
        else {
            reduceDuplicatedElements(list);// loại bỏ các phần tử trùng nhau
            int index = k;
            auto it = list.cbegin();
            while (it != list.cend() && index > 1) {
                it++;
                index--;
            }
            // nếu sau quá trình tìm mà index == 1 và it chưa duyệt đến vị trí sau phần tử cuối
            if (index == 1 && it != list.cend()) { // tìm thấy, in ra giá trị cần tìm
                cout << "Gia tri phan tu lon thu " << k << ": " << *it << endl;
            }
            else { // không tồn tại giá trị thỏa mãn
                cout << "Khong co gia tri lon thu " << k << endl;
            }
        }
    }
}

int main() {
    forward_list<int> listInt;      // khai báo forward_list kiểu int
    int k;
    // nhập vào các phần tử cho forward_list
    cout << "Nhap cac so nguyen int: \n";
    fillElements(listInt);
    cout << "Nhap k: ";
    cin >> k;
   
    // hiển thị các phần tử trong forward_list int
    cout << "Cac phan tu mang int: ";
    showListElements(listInt);

    // hiển thị kết luận tìm phần tử lớn thứ k trong danh sách
    findMaxKth(listInt, k);

    return 0;
}
