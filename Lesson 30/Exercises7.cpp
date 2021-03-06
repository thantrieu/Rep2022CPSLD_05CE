/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

void getArrayElements(int arr[], size_t& size);
void showResult(int min, int max);
void findMinMax(const int arr[], size_t size, int& min, int& max);

int main()
{
    int numbers[SIZE]; // khai báo mảng nguyên tối đa SIZE phần tử
    size_t n;
    getArrayElements(numbers, n);
    // tìm min, max:
    int min, max;
    findMinMax(numbers, n, min, max);
    showResult(min, max);

    return 0;
}

void showResult(int min, int max) {
    if (min == max) {
        cout << "NOT AVAILABLE";
    }
    else {
        cout << min << " " << max;
    }
    cout << endl;
}

// định nghĩa hàm nhập liệu các phần tử cho mảng
void getArrayElements(int arr[], size_t& size) {
    int n;
    cout << "Nhap vao so nguyen duong n: ";
    cin >> n;
    if (n <= 0) {
        cout << "N INVALID" << endl;
    }
    else {
        size = n;
        // đọc vào các phần tử của mảng:
        cout << "Nhap " << size << " phan tu cua mang: " << endl;
        for (size_t i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
}

void findMinMax(const int arr[], size_t size, int& min, int& max) {
    min = arr[0];
    max = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
}
