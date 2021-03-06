/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <cstring>
using namespace std;

// hàm loại bỏ dấu cách thừa:
void removeDuplicateWhiteSpace(char* str);
// hàm đếm số dấu cách đầu chuỗi
int countLeadingWhiteSpace(const char* str);
// hàm loại bỏ các kí tự khoảng trắng ở đầu chuỗi
void removeLeadingWhiteSpace(char* str);
// hàm loại bỏ kí tự khoảng trắng cuối chuỗi
void removeTrailingWhiteSpace(char* str);

int main()
{
	char str[200];
	cout << "Nhap vao chuoi ki tu: ";
	cin.getline(str, 200);
	// loại bỏ khoảng trắng đầu chuỗi
	removeLeadingWhiteSpace(str);
	// loại bỏ dấu cách cuối chuỗi
	removeTrailingWhiteSpace(str);
	// loại bỏ dấu cách trùng lặp trong chuỗi
	removeDuplicateWhiteSpace(str);
	cout << "Result: \"" << str << "\"" << endl;

	return 0;
}

void removeTrailingWhiteSpace(char* str) {
	int length = strlen(str); // xuất phát từ cuối chuỗi
	while (str[length - 1] == ' ') { // nếu phần tử cuối chuỗi vẫn là khoảng trắng
		str[length - 1] = '\0'; // gán phần tử đó là kí tự kết thúc chuỗi
		length--;
	}
}

void removeDuplicateWhiteSpace(char* str) {
	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		// nếu gặp hai dấu cách liên tiếp
		if (str[i] == str[i + 1] && str[i] == ' ') {
			// dịch trái các kí tự phía bên phải của dấu cách thứ nhất
			for (int  j = i; j < size; j++) // bao gồm cả kí tự '\0'
			{
				str[j] = str[j + 1];
			}
			i--; // xét lại phòng trường hợp có nhiều dấu cách liên tiếp
			size--; // giảm kích thước chuỗi
		}
	}
}

// đếm số kí tự khoảng trắng đầu chuỗi
int countLeadingWhiteSpace(const char* str) {
	int i = 0;
	while (str[i] == ' ') {
		i++;
	}
	return i;
}

void removeLeadingWhiteSpace(char* str) {
	int distance = countLeadingWhiteSpace(str);
	int size = strlen(str); // lấy độ dài chuỗi 
	for (int i = 0; i < size - distance; i++)
	{	// dịch sang trái 1 lượng bằng distance
		str[i] = str[i + distance];
	}
}