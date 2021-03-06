#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string replaceAll(string str, string str1, string str2) {
	auto index = str.find(str1); // tìm vị trí của str1 trong str
	while (index != string::npos) { // chừng nào còn str1 trong str
		str = str.replace(index, str1.length(), str2); // thay thế str1 bởi str2
		index = str.find(str1); // tiếp tục tìm
	}
	return str; // trả về kết quả
}

int main() {
	int t;
	ifstream ifs("input16.txt");
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
			auto result = replaceAll(str1, str2, str3); // kết quả
			cout << "Test " << testCount++ << ": " << result << endl;
		}
		ifs.close();
	}
	else {
		cout << "Khong mo duoc file. Vui long kiem tra lai.\n";
	}
}
