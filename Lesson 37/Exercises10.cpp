/**
 * @author Branium Academy
 * @see https://braniumacademy.net
 * @version 2022.02.16
 */

#include <iostream>
#include <cmath>

using namespace std;
#define SIZE 100

// hàm nhập số phần, x và các phần tử của mảng
void getArrayElements(int* arr, int& n);
// hàm hiển thị các phần tử của mảng theo thứ tự ngược lại
void showArrayElements(const int* arr, int n);
// hàm kiểm tra tính đối xứng của mảng
bool isSymmetry(const int* arr, int n);
// hàm đếm số lượng các số nguyên tố
int countPrimeNumbers(const int* arr, int n);

int main()
{
    int n;
    int arr[SIZE];
    getArrayElements(arr, n);
    if (n > 0) {
        showArrayElements(arr, n);
        if (isSymmetry(arr, n)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        cout << countPrimeNumbers(arr, n) << endl;
    }

    return 0;
}

// hàm kiểm tra mảng có đối xứng không
bool isSymmetry(const int* arr, int n) {
    for (int i = 0; i <= n / 2; i++)
    {
        if (*(arr + i) != *(arr + n - i - 1)) {
            return false;
        }
    }
    return true;
}

// hàm đếm số lượng các số nguyên tố trong mảng
int countPrimeNumbers(const int* arr, int n) {
    int count = 0;
    bool isPrime(int);
    for (int i = 0; i < n; i++)
    {
        if (isPrime(*(arr + i))) {
            count++;
        }
    }
    return count;
}

// hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// nhập giá trị cho các phần tử trong mảng
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

// hiển thị các phần tử mảng theo thứ tự từ cuối lên đầu
void showArrayElements(const int* arr, int n) {
    for (int i = n - 1; i >= 0; i--)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}