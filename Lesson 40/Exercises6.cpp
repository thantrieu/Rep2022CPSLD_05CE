/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.04
 *
 */
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void drawTriangle(string** triangle, const int height);
void showTriangle(string** triangle, const int height);

int main()
{
	int height;
	cout << "Nhap chieu cao tam giac: ";
	cin >> height;
	if (height > 0) {
		// cấp phát động:
		string** triangle = new string*[height];
		for (int i = 0; i < height; i++) {
			triangle[i] = new string[2 * height];
		}
		drawTriangle(triangle, height);
		showTriangle(triangle, height);
		// thu hồi bộ nhớ:
		for (int i = 0; i < height; i++) {
			delete[] triangle[i];
		}
		delete[] triangle;
	}
	else {
		cout << "ERROR" << endl;
	}
	return 0;
}

void drawTriangle(string** triangle, const int height) {
	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= 2 * height - 1; j++) {
			if (j >= (height - i + 1) && j <= (height + i - 1)) {
				triangle[i - 1][j - 1] = to_string((i - abs(height - j)));
			}
			else {
				triangle[i - 1][j - 1] = " ";
			}
		}
	}
}

void showTriangle(string** triangle, const int height) {
	int bound = 2 * height - 1;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < bound; j++)
		{
			cout << left << setw(5) << triangle[i][j];
		}
		cout << endl;
	}
}