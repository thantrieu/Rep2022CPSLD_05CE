#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int findResult(string str1, string str2) {
	int result = 0;
	int prev = 0;
	for (size_t i = 1; i < str2.length(); i++)
	{
		if (str2.at(i) == ' ') { // nếu tại vị trí i là dấu cách
			string word = str2.substr(prev, i - prev); // trích lấy cụm từ cần xét
			string beforeWord = str2.substr(0, prev); // trích lấy đoạn phía trước khi từ đang xét
			if (beforeWord.find(word) == string::npos &&
				str1.find(word) != string::npos) { // nếu từ đang xét chưa xuất hiện trước đó
				result++; // và từ đó tồn tại ở cả trong str1, tăng biến đếm lên
			}
			prev = i + 1; // cập nhật vị trí sau dấu cách
		}
	}
	return result;
}

int main() {
	int t;
	ifstream ifs("input14.txt");
	int testCount = 1;
	if (ifs) {
		ifs >> t;
		ifs.ignore();
		string str1;
		string str2;
		while (t--) {
			getline(ifs, str1); // đọc vào str1
			getline(ifs, str2); // đọc vào str2
			auto result = findResult(str1, str2); // kết quả
			cout << "Test " << testCount++ << ": " << result << endl;
		}
		ifs.close();
	}
	else {
		cout << "Khong mo duoc file. Vui long kiem tra lai.\n";
	}
}