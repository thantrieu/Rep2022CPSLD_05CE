#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string replaceAll(string str1, string str2, char c) {
	for (size_t i = 0; i < str1.length(); i++)
	{
		if (str1.at(i) == c) {
			str1 = str1.replace(i, 1, str2);
			i = i + str2.length() - 1; // cập nhật lại vị trí i để tránh trùng lặp
		}
	}
	return str1;
}

int main() {
	int t;
	ifstream ifs("input15.txt");
	int testCount = 1;
	if (ifs) {
		ifs >> t;
		ifs.ignore();
		string str1;
		string str2;
		string str3;
		while (t--) {
			getline(ifs, str1); // đọc vào str1
			getline(ifs, str2); // đọc vào str2
			getline(ifs, str3); // đọc cả dòng chứa kí tự c
			auto result = replaceAll(str1, str2, str3.at(0)); // kết quả
			cout << "Test " << testCount++ << ": " << result << endl;
		}
		ifs.close();
	}
	else {
		cout << "Khong mo duoc file. Vui long kiem tra lai.\n";
	}
}