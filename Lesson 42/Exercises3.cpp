/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <cstring>
using namespace std;

// khai báo nguyên mẫu:
// hàm hiển thị kết quả
void showResult(char** words, const int size);
// hàm kiểm tra một từ có tồn tại trong danh sách không
bool check(char** words, const int size, const char* word);
// hàm tách chuỗi thành từng từ
void split(char* str, char** words, int& size);
// hàm đếm số lần xuất hiện của từng từ
void countOccurrent(char** words, const int size);
// hàm hiển thị các phần tử duy nhất 1 lần
void showUniqueWords(char** words, const int size);

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
	cout << "Kich thuoc chuoi ki tu: " << strlen(str) << endl;
	split(str, words, size);

	cout << "Danh sach cac tu trong chuoi str: " << endl;
	showResult(words, size);
	cout << "Danh sach cac tu da luoc bo trung lap: " << endl;

	showUniqueWords(words, size);
	cout << "Danh sach cac tu va so lan xuat hien: " << endl;
	countOccurrent(words, size);

	return 0;
}

void showUniqueWords(char** words, const int size) {
	for (int i = 0; i < size; i++)
	{
		if (!check(words, i, words[i])) {
			cout << words[i] << " ";
		}
	}
	cout << endl;
}

void showResult(char** words, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "" << words[i] << " ";
	}
	cout << endl;
}

bool check(char** words, const int size, const char* word) {
	for (int i = 0; i < size; i++)
	{
		if (strcmp(words[i], word) == 0) {
			return true;
		}
	}
	return false;
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

void countOccurrent(char** words, const int size) {
	for (int i = 0; i < size; i++)
	{
		if (!check(words, i, words[i])) {
			cout << words[i] << ": ";
			int count = 0;
			for (int j = 0; j < size; j++)
			{
				if (strcmp(words[j], words[i]) == 0) {
					count++;
				}
			}
			cout << count << endl;
		}
	}
}
