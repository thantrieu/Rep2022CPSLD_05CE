/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>

using namespace std;
#define SIZE 100

// hàm nhập số phần, x và các phần tử của mảng
void getArrayElements(int* arr, int& n);
// hàm hiển thị các phần tử của mảng
void showArrayElements(const int* arr, int n);
// hàm tìm độ dài đường chạy tăng dài nhất
int maxLength(const int* arr, int n);
// hàm liệt kê các kết quả tìm được
void showResult(const int* arr, int n);

int main()
{
    int n;
    int arr[SIZE];
    getArrayElements(arr, n);
    if (n > 0) {
        showArrayElements(arr, n);
        showResult(arr, n);
    }

    return 0;
}

int maxLength(const int* arr, int n) {
    int count = 1; // biến đếm số phần tử của đường chạy
    int max = 1; // độ dài lớn nhất mặc định là 1
    int i;
    for (i = 0; i < n; i++) {
        // nếu phần tử sau nhỏ hơn phần tử trước
        if (i + 1 < n && *(arr + i) <= *(arr + i + 1)) {
            count++;
        }
        else { // phần tử kế tiếp thuộc đường chạy khác
            if (count > max) {
                max = count;
            }
            count = 1; // reset lại biến count
        }
    }
    return max; // trả về độ dài max tìm đc
}

void showResult(const int* arr, int n) {
    void showElementsInRange(const int*, int, int);
    int countResult = 0;
    int max = maxLength(arr, n);
    cout << max << endl;
    int startIndex = 0;
    int curLen = 1; // độ dài mặc định của một đường chạy
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && *(arr + i) <= *(arr + i + 1)) {
            curLen++;
        }
        else { // phần tử kế tiếp thuộc đường chạy khác
            if (curLen == max) { // nếu là đường chạy max
                if (countResult > 0) {
                    cout << ", ";
                }
                showElementsInRange(arr, startIndex, startIndex + max);
                countResult++;
            }
            curLen = 1; // reset lại biến giám sát độ dài đường chạy
            startIndex = i + 1;// đánh dấu vị trí bắt đầu đ.chạy mới
        }
    }
}

void showElementsInRange(const int* arr, int from, int to) {
    for (int j = from; j < to - 1; j++) {
        cout << *(arr + j) << " ";
    }
    cout << *(arr + to - 1);
}

void getArrayElements(int* arr, int& n) {
    cin >> n;
    if (n < 0 || n > 100) {
        cout << "N INVALID" << endl;
    }
    else {
        for (int i = 0; i < n; i++)
        {
            cin >> *(arr + i);
        }
    }
}

void showArrayElements(const int* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}