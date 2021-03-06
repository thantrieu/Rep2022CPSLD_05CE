/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 *
 */
#include <iostream>

using namespace std;

void drawRectangle(string** rect, int& m, int& n);
void showRectangle(string** rect, int m, int n);

int main()
{
	int m, n;
	cout << "Nhap so hang, cot: ";
	cin >> m >> n;
	if (m > 0 && n > 0) {
		string** rect;
		// cấp phát:
		rect = new string *[m];
		for (int i = 0; i < m; i++) {
			rect[i] = new string[n];
		}
		drawRectangle(rect, m, n);
		cout << endl;
		showRectangle(rect, m, n);
		// thu hồi:
		for (int i = 0; i < m; i++) {
			delete[] rect[i];
		}
		delete[] rect;
	}
	else {
		cout << "ERROR" << endl;
	}
	return 0;
}

void drawRectangle(string** rect, int& m, int& n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
				rect[i][j] = " * ";
			}
			else {
				rect[i][j] = "   ";
			}
		}
	}
}

void showRectangle(string** rect, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << rect[i][j];
		}
		cout << endl;
	}
}