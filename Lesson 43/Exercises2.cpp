/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <cstring>
using namespace std;

void split(char* str);
char* toUpper(char* str);
void sort(char** words, const int size); // sx giảm dần
void showResult(char** words, const int size);
void showUpperFirstLetter(char** words, const int size);

int main()
{
	int n; // số bộ test
	int i = 1;
	char str[500];
	cin >> n;
	cin.ignore();
	while (i <= n) {
		cin.getline(str, 500);
		cout << "Test " << i << ": " << endl;
		split(str);
		i++;
	}
	return 0;
}

void sort(char** words, const int size) {
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (strcmp(words[j], words[j - 1]) > 0) {
				swap(words[j], words[j - 1]);
			}
		}
	}
}

char* toUpper(char* str) {
	str[0] = toupper(str[0]);
	return str;
}

void split(char* str) {
	const char* delim = ".,?!;:\t ";
	char* p = strtok(str, delim);
	int size = 0;
	char** words = new char* [200];
	for (int i = 0; i < 200; i++)
	{
		words[i] = new char[20];
	}
	// giả định mỗi từ có tối đa 20 kí tự và danh sách gồm tối đa 200 từ
	while (p != nullptr) {
		strcpy(words[size++], p);
		p = strtok(nullptr, delim);
	}
	showResult(words, size); // hiện danh sách từ
	showUpperFirstLetter(words, size);
	sort(words, size);
	showResult(words, size);
}

void showResult(char** words, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << words[i] << " ";
	}
	cout << endl;
}

void showUpperFirstLetter(char** words, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << toUpper(words[i]) << " ";
	}
	cout << endl;
}
