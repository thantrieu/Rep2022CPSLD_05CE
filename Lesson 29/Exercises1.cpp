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
        // đọc vào các phần tử của mảng:
        for (size_t i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }
        // tính tổng các phần tử trong mảng:
        int sum = 0; // khởi tạo biến tổng
        for (size_t i = 0; i < n; i++)
        {
            sum += numbers[i];
        }
        cout << sum << endl;
    }

    return 0;
}