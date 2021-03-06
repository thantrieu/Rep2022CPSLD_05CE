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
int countX(const int arr[], int n, int x);

int main()
{
    int n;
    int x;
    int arr[SIZE];
    getArrayElements(arr, n, x);
    if (n > 0) {
        showArrayElements(arr, n);
        int result = countX(arr, n, x);
        cout << result << endl;
    }

    return 0;
}

int countX(const int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
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