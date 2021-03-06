/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.03
 */

#include <iostream>

using namespace std;
#define SIZE 100

void getArrayElements(double arr[], int& n);
void showArrayElements(const double arr[], int n);
void quicksort(double arr[], int leftIndex, int rightIndex);
void bubbleSort(double arr[], int n);

int main()
{
    int n;
    double arr[SIZE];
    getArrayElements(arr, n);

    cout << "Cac phan tu trong mang: " << endl;
    showArrayElements(arr, n);

    quicksort(arr, 0, n - 1);
    cout << "Mang sau khi sap xep tang dan: " << endl;
    showArrayElements(arr, n);

    bubbleSort(arr, n);
    cout << "Mang sau khi sap xep giam dan: " << endl;
    showArrayElements(arr, n);

    return 0;
}

void getArrayElements(double arr[], int& n) {
    cout << "Nhap so phan tu cua mang[1-100]: ";
    cin >> n;
    if (n < 0 || n > 100) {
        cout << "Vui long nhap so n trong doan [1-100]." << endl;
    }
    else {
        for (int i = 0; i < n; i++)
        {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }
}

void showArrayElements(const double arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// hàm sắp xếp nhanh các phần tử theo thứ tự tăng dần
void quicksort(double arr[], int leftIndex, int rightIndex) {
    int partition(double[], int, int);
    if (leftIndex < rightIndex) {
        int p = partition(arr, leftIndex, rightIndex);
        quicksort(arr, leftIndex, p - 1);
        quicksort(arr, p + 1, rightIndex);
    }
}
// hàm sắp xếp nổi bọt các phần tử theo thứ tự giảm dần
void bubbleSort(double arr[], int n) {
    bool isSwapped = true;
    int i = 0;
    while (i < n) {
        isSwapped = false;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] > arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped) {
            break;
        }
        else {
            i++;
        }
    }
}

int partition(double arr[], int left, int right) {
    double pivot = arr[right];
    int i = left;
    for (int j = left; j <= right; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i = i + 1;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}
