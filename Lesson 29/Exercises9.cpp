/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

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
        // nhập x:
        int x;
        cin >> x;
        // tìm số lần xuất hiện của x trong mảng:
        int countX = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (numbers[i] == x) {
                countX++;
            }
        }
        // kết quả:
        cout << countX << endl;
    }

    return 0;
}