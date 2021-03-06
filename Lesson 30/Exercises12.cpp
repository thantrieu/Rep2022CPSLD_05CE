/**
 *@author Branium Academy
 *@website braniumacademy.net
 *@version 2021.03
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define SIZE 1000 // tối đa 1000 phần tử

void getArraySize(size_t& size);
void generateRandomElements(int arr[], size_t size);
void showResult(const int arr[], size_t size);

int main()
{
	int numbers[SIZE]; // mảng nguyên tối đa SIZE phần tử
	size_t n;
	getArraySize(n);
	generateRandomElements(numbers, n);
	showResult(numbers, n);
	return 0;
}

void getArraySize(size_t& size) {
	int n;
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	if (n <= 0 || n > 1000) {
		cout << "N INVALID" << endl;
	}
	else {
		size = n;
	}
}

bool isElementExisted(const int arr[], size_t size, int x) {
		// kiểm tra xem giá trị vừa sinh ra đã tồn tại hay chưa:
	for (size_t j = 0; j < size; j++)
	{
		if (arr[j] == x) { // x đã tồn tại
			return true;
		}
	}
	return false;
}

void generateRandomElements(int arr[], size_t size) {
	bool isElementExisted(const int[], size_t, int);
	srand(time(NULL)); // để sinh số ngẫu nhiên không trùng nhau
		// tạo ngẫu nhiên các phần tử của mảng:
	size_t countGenerated = 0;
	for (size_t i = 0; i < size; i++)
	{
		int x = 1 + rand() % 1000;
		bool isExisted = isElementExisted(arr, countGenerated, x);
		if (!isExisted) { // nếu x chưa tồn tại
			arr[i] = x; // gán x cho numbers[i]
			countGenerated++; // tăng biến giám sát lên
		}
		else { // nếu x đã tồn tại, không tăng biến chạy i
			i--; // để tìm bằng được giá trị khác mới tăng i
		}
	}
}

void showResult(const int arr[], size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}