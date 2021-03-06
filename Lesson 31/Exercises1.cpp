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
void bubbleSortASC(int arr[], int n);
void bubbleSortDESC(int arr[], int n);

int main()
{
    int n;
    int arr[SIZE];
    getArrayElements(arr, n);

    cout << "Cac phan tu trong mang: " << endl;
    showArrayElements(arr, n);

    bubbleSortASC(arr, n);
    cout << "Mang sau khi sap xep tang dan: " << endl;
    showArrayElements(arr, n);

    bubbleSortDESC(arr, n);
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
// hàm sắp xếp nổi bọt tăng dần
void bubbleSortASC(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}
// hàm sắp xếp nổi bọt giảm dần
void bubbleSortDESC(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] > arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}