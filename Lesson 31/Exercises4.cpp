/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.03
 */

#include <iostream>

using namespace std;
#define SIZE 100

void getArrayElements(int arr[], int& n);
void showArrayElements(const int arr[], int n);
void quicksortASC(int arr[], int leftIndex, int rightIndex);
void quicksortDESC(int arr[], int leftIndex, int rightIndex);

int main()
{
    int n;
    int arr[SIZE];
    getArrayElements(arr, n);

    cout << "Cac phan tu trong mang: " << endl;
    showArrayElements(arr, n);

    quicksortASC(arr, 0, n - 1);
    cout << "Mang sau khi sap xep tang dan: " << endl;
    showArrayElements(arr, n);

    quicksortDESC(arr, 0, n - 1);
    cout << "Mang sau khi sap xep giam dan: " << endl;
    showArrayElements(arr, n);

    return 0;
}

void getArrayElements(int arr[], int& n) {
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

void showArrayElements(const int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// hàm sắp xếp nhanh các phần tử theo thứ tự tăng dần
void quicksortASC(int arr[], int leftIndex, int rightIndex) {
    int partition1(int[], int, int);
    if (leftIndex < rightIndex) {
        int p = partition1(arr, leftIndex, rightIndex);
        quicksortASC(arr, leftIndex, p - 1);
        quicksortASC(arr, p + 1, rightIndex);
    }
}
// hàm sắp xếp nhanh các phần tử theo thứ tự giảm dần
void quicksortDESC(int arr[], int leftIndex, int rightIndex) {
    int partition2(int[], int, int);
    if (leftIndex < rightIndex) {
        int p = partition2(arr, leftIndex, rightIndex);
        quicksortDESC(arr, leftIndex, p - 1);
        quicksortDESC(arr, p + 1, rightIndex);
    }
}

int partition1(int arr[], int left, int right) {
    int pivot = arr[right];
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

int partition2(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j <= right; j++) {
        if (arr[j] > pivot) {
            swap(arr[i], arr[j]);
            i = i + 1;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}