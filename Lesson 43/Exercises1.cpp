/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <cstring>
using namespace std;

char* toUpper(char* str);
char* toLower(char* str);

int main()
{
	int n; // số bộ test
	int i = 1;
	char str[500];
	cin >> n;
	cin.ignore();
	while (i <= n) {
		cout << "Test " << i << ": " << endl;
		cin.getline(str, 500);
		cout << toUpper(str) << endl;
		cout << toLower(str) << endl;
		i++;
	}
	return 0;
}

char* toUpper(char* str) {
	for (size_t i = 0; i < strlen(str); i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

char* toLower(char* str) {
	for (size_t i = 0; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}