/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.04
 */

#include <iostream>

using namespace std;
#define SIZE 100

void getArrayElements(int arr[], int& n, int& x);
void showArrayElements(const int arr[], int n);
int findX(const int arr[], const int n, const int x);

int main()
{
    int n;
    int x;
    int arr[SIZE];
    getArrayElements(arr, n, x);
    if (n > 0) {
        showArrayElements(arr, n);
        int xIndex = findX(arr, n, x);
        if (xIndex != -1) {
            cout << "FOUND" << endl;
        }
        else {
            cout << "NOT FOUND" << endl;
        }
    }

    return 0;
}

int findX(const int arr[], const int n, const int x) {
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

void getArrayElements(int arr[], int& n, int& x) {
    cin >> n;
    if (n < 0 || n > 100) {
        cout << "N INVALID" << endl;
    }
    else {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> x;
    }
}

void showArrayElements(const int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}