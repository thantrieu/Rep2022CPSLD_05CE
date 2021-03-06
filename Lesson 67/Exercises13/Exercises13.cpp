#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int t;
	ifstream ifs("input13.txt");
	int testCount = 1;
	if (ifs) {
		ifs >> t;
		ifs.ignore();
		string str1;
		string str2;
		while (t--) {
			int result = 0; // biến lưu kết quả
			getline(ifs, str1); // đọc vào str1
			getline(ifs, str2); // đọc vào str2
			auto lenStr2 = str2.length(); // lấy độ dài str2
			auto index = str1.find(str2); // tìm vị trí str2 trong str1
			while (index != string::npos) { // nếu còn tìm thấy
				result++; // tăng biến đếm lên
				str1 = str1.substr(index + lenStr2); // cập nhật lại str1
				index = str1.find(str2); // tìm vị trí kế tiếp
			}
			cout << "Test " << testCount++ << ": " << result << endl;
		}
		ifs.close();
	}
	else {
		cout << "Khong mo duoc file. Vui long kiem tra lai.\n";
	}
}