/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 *
 */
#include <iostream>

using namespace std;

void getMatrixElements(double** matrix, const int m, const int n);
void showMatrixElements(double** matrix, const int m, const int n);
void transpose(double** matrix, double** result, const int m, const int n);

int main()
{
    double** matrix;
    int m, n;
    cout << "Nhap cap ma tran: ";
    cin >> m >> n;
    if (m > 0 && n > 0) {
        matrix = new double* [m];
        for (int i = 0; i < m; i++) {
            matrix[i] = new double[n]();
        }
        // nhập các phần tử cho ma trận
        getMatrixElements(matrix, m, n);
        // hiện kết quả
        showMatrixElements(matrix, m, n);
        // khai báo mảng hai chiều lưu ma trận chuyển vị
        double** result = new double* [n];
        for (int i = 0; i < n; i++) {
            result[i] = new double[m]();
        }
        transpose(matrix, result, m, n);
        cout << endl;
        showMatrixElements(result, n, m);
        // giải phóng bộ nhớ:
        for (int i = 0; i < m; i++) {
            delete [] matrix[i];
        }
        delete[] matrix;

        for (int i = 0; i < n; i++) {
            delete result[i];
        }
        delete[] result;
    }
    else {
        cout << "ERROR" << endl;
    }
    return 0;
}

void transpose(double** matrix, double** result, const int m, const int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }
}

void getMatrixElements(double** matrix, const int m, const int n) { 
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
}

void showMatrixElements(double** matrix, const int m, const int n) {
    cout << m << " " << n << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}