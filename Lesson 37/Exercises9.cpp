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
void getArrayElements(int* arr, int& n, int& x);
// hàm hiển thị các phần tử của mảng
void showArrayElements(const int* arr, int n);
// hàm tìm và hiển thị các giá trị gần x nhất
void findNearest(const int* arr, int n, int x);
// hàm tìm và hiển thị các giá trị xa x nhất
void findfurthest(const int* arr, int n, int x);

int main()
{
    int n;
    int x;
    int arr[SIZE];
    getArrayElements(arr, n, x);
    if (n > 0) {
        showArrayElements(arr, n);
        findNearest(arr, n, x);
        cout << endl;
        findfurthest(arr, n, x);
    }

    return 0;
}

void findNearest(const int* arr, int n, int x) {
    int minDistance = abs(arr[0] - x);
    for (int i = 1; i < n; i++)
    {
        int tmp = abs(*(arr + i) - x);
        if (tmp < minDistance) {
            minDistance = tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (abs(*(arr + i) - x) == minDistance) {
            cout << "(" << *(arr + i) << ", " << i << ") ";
        }
    }
}

void findfurthest(const int* arr, int n, int x) {
    int minDistance = abs(arr[0] - x);
    for (int i = 1; i < n; i++)
    {
        int tmp = abs(*(arr + i) - x);
        if (tmp > minDistance) {
            minDistance = tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (abs(*(arr + i) - x) == minDistance) {
            cout << "(" << *(arr + i) << ", " << i << ") ";
        }
    }
}

void getArrayElements(int* arr, int& n, int& x) {
    cin >> n;
    if (n < 0 || n > 100) {
        cout << "N INVALID" << endl;
    }
    else {
        for (int i = 0; i < n; i++)
        {
            cin >> *(arr + i);
        }
        cin >> x;
    }
}

void showArrayElements(const int* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}