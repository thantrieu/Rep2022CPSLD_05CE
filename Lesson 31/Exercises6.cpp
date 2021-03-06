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
int countMaxElements(const double arr[], int n);
int countMinElements(const double arr[], int n);
double findMin2(const double arr[], int n);
double findMax2(const double arr[], int n);

int main()
{
    int n;
    double arr[SIZE];
    getArrayElements(arr, n);

    cout << "Cac phan tu trong mang: " << endl;
    showArrayElements(arr, n);

    quicksort(arr, 0, n - 1);
    // sau khi sắp xếp tăng, phần tử cuối cùng của mảng
    // là phần tử có giá trị lớn nhất
    cout << "Gia tri max: " << arr[n - 1] << endl;
    cout << "So phan co gia tri max: ";
    cout << countMaxElements(arr, n) << endl;

    // sau khi sắp xếp tăng, phần tử đầu tiên trong mảng là phần tử
    // có giá trị nhỏ nhất
    cout << "Gia tri min: " << arr[0] << endl;
    cout << "So phan tu co gia tri min: ";
    cout << countMinElements(arr, n) << endl;

    // tìm giá trị nhỏ thứ 2 trong mảng:
    double min2 = findMin2(arr, n);
    if (min2 != arr[0]) {
        cout << "Min2 = " << min2<< endl;
    }
    else {
        cout << "Khong co gia tri min2" << endl;
    }
    
    // tìm giá trị lớn thứ 2 trong mảng:
    double max2 = findMax2(arr, n);
    if (max2 != arr[n - 1]) {
        cout << "Max2 = " << max2 << endl;
    }
    else {
        cout << "Khong co gia tri max2" << endl;
    }

    return 0;
}

int countMaxElements(const double arr[], int n) {
    int counter = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == arr[n - 1]) {
            counter++;
        }
        if (arr[i] < arr[n - 1]) {
            break;
        }
    }
    return counter;
}

int countMinElements(const double arr[], int n) {
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[0]) {
            counter++;
        }
        if (arr[i] > arr[0]) {
            break;
        }
    }
    return counter;
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

// để tìm min2, ta xuất phát từ đầu mảng, tìm phần tử
// đầu tiên có giá trị > giá trị phần tử đầu tiên của mảng
// đó chính là min2
double findMin2(const double arr[], int n) {
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[0]) {
            return arr[i];
        }
    }
    return arr[0]; // mặc định return giá trị min
}

// để tìm max2, ta xuất phát từ cuối mảng, tìm phần tử
// đầu tiên có giá trị < giá trị của phần tử cuối trong mảng
// đó là phần tử max2
double findMax2(const double arr[], int n) {
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[n - 1]) {
            return arr[i];
        }
    }
    return arr[n - 1]; // mặc định return giá trị max
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
