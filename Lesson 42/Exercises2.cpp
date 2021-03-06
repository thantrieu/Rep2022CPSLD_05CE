/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <cstring>
using namespace std;

// hàm hiển thị kết quả
void showResult(char** words, const int size);
// hàm sắp xếp tăng dần
void sort(char** words, const int size);
// hàm phân tách chuỗi thành các từ
void split(char* str, char** words, int& size);

int main()
{
	char str[200];
	int size = 0; // số từ có trong danh sách
	char** words = new char* [200]; // danh sách tối đa 200 từ
	for (int i = 0; i < 200; i++)
	{
		words[i] = new char[20]; // mỗi từ tối đa 20 kí tự cả null
	}
	cout << "Nhap vao chuoi ki tu: ";
	cin.getline(str, 200);
	split(str, words, size);

	cout << "Danh sach cac tu trong chuoi str: ";
	showResult(words, size);
	cout << "So luong tu co trong chuoi: " << size << endl;

	sort(words, size);
	cout << "Danh sach cac tu sau khi sap xep a-z: ";
	showResult(words, size);

	return 0;
}

// hàm hiển thị kết quả
void showResult(char** words, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "" << words[i] << " ";
	}
	cout << endl;
}

void sort(char** words, const int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (strcmp(words[j], words[j - 1]) < 0) {
				swap(words[j], words[j - 1]);
			}
		}
	}
}

void split(char* str, char** words, int& size) {
	// giả định các từ chỉ cách nhau bởi dấu cách, tab, 
	// dấu chấm, phẩy, hỏi, than, hai chấm, và dấu chấm phẩy
	const char* delim = ".,?;:!\t "; // các kí tự để tìm chỗ phân tách
	char* word = strtok(str, delim);
	while (word != nullptr) {
		strcpy(words[size++], word);
		word = strtok(nullptr, delim);
	}
}