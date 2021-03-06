/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử
// khai báo nguyên mẫu hàm:
bool isPrime(int n);

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
        // liệt kê các số nguyên tố:
        for (size_t i = 0; i < size; i++)
        {
            if (isPrime(numbers[i])) {
                cout << "(" << i << ", " << numbers[i] << ") ";
            }
        }
    }

    return 0;
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    size_t upperBound = sqrt(n);
    for (size_t i = 2; i <= upperBound; i++)
    {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}