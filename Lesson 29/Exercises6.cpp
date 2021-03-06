/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

bool isReversed(int n);

int main()
{
    int numbers[SIZE]; // khai báo mảng nguyên tối đa SIZE phần tử
    int n;
    cout << "Nhap vao so nguyen duong n: ";
    cin >> n;
    if (n <= 0) {
        cout << "N INVALID" << endl;
    }
    else {
        size_t size = n;
        // đọc vào các phần tử của mảng:
        for (size_t i = 0; i < size; i++)
        {
            cin >> numbers[i];
        }
        // hiển thị các phần tử là số thuận nghịch trong mảng:
        for (size_t i = 0; i < size; i++)
        {
            if (isReversed(numbers[i])) {
                cout << numbers[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

bool isReversed(int n) {
    n = (n < 0) ? -n : n; // bỏ dấu của n nếu n < 0
    if (n < 10) {
        return false;
    }
    int rev = 0;
    for (int i = n; i > 0; i /= 10)
    {
        rev = rev * 10 + i % 10;
    }
    return rev == n;
}