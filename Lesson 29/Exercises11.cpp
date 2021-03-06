/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>

using namespace std;

#define SIZE 100 // tối đa 100 phần tử

int main()
{
	int numbers[SIZE];
	int n;
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	if (n <= 0) {
		cout << "N INVALID" << endl;
	}
	else {
		size_t size = n;
		for (size_t i = 0; i < size; i++)
		{
			cin >> numbers[i];
		}
		// kiểm tra đối xứng:
		bool isSymmetrical = true;
		for (size_t i = 0; i < size; i++)
		{
			if (numbers[i] != numbers[n - 1 - i]) {
				isSymmetrical = false;
				break;
			}
		}
		cout << (isSymmetrical ? "YES" : "NO") << endl;
	}

	return 0;
}