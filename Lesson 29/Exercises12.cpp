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

int main()
{
	int numbers[SIZE]; // mảng nguyên tối đa SIZE phần tử
	int n;
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	if (n <= 0 || n > 1000) {
		cout << "N INVALID" << endl;
	}
	else {
		size_t size = n;
		srand(time(NULL)); // để sinh số ngẫu nhiên không trùng nhau
		// tạo ngẫu nhiên các phần tử của mảng:
		int countGenerated = 0;
		for (size_t i = 0; i < size; i++)
		{
			int x = 1 + rand() % 1000;
			bool isExisted = false; // giả định x chưa tồn tại trong mảng
			// kiểm tra xem giá trị vừa sinh ra đã tồn tại hay chưa:
			for (size_t j = 0; j < countGenerated; j++)
			{
				if (numbers[j] == x) { // x đã tồn tại
					isExisted = true;
					break;
				}
			}
			if (!isExisted) { // nếu x chưa tồn tại
				numbers[i] = x; // gán x cho numbers[i]
				countGenerated++; // tăng biến giám sát lên
			}
			else { // nếu x đã tồn tại, không tăng biến chạy i
				i--; // để tìm bằng được giá trị khác mới tăng i
			}
		}
		// kết quả:
		for (size_t i = 0; i < size; i++)
		{
			cout << numbers[i] << " ";
		}
		cout << endl;
	}

	return 0;
}