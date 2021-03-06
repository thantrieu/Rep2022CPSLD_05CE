/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <cmath>

using namespace std;
#define SIZE 100

// hàm nhập số phần, x và các phần tử của mảng
void getArrayElements(double* arr, int& n);
// hàm hiển thị các phần tử của mảng
void showArrayElements(const double* arr, int n);
// sắp xếp mảng theo thứ tự tăng dần
void sortASC(double* arr, int n);

int main()
{
    int n;
    double arr[SIZE];
    getArrayElements(arr, n);
    if (n > 0) {
        sortASC(arr, n);
        showArrayElements(arr, n);
    }

    return 0;
}

void sortASC(double* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (*(arr + j) < *(arr + j - 1)) {
                swap(*(arr + j), *(arr + j - 1));
            }
        }
    }
}

void getArrayElements(double* arr, int& n) {
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

void showArrayElements(const double* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}