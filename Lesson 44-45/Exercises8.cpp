#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	int testCount = 1;
	cin >> t;
	cin.ignore();
	string str1;
	string str2;
	while (t--) {
		int result = 0; // biến lưu kết quả
		getline(cin, str1); // đọc vào str1
		getline(cin, str2); // đọc vào str2
		auto lenStr2 = str2.length(); // lấy độ dài str2
		auto index = str1.find(str2); // tìm vị trí str2 trong str1
		while (index != string::npos) { // nếu còn tìm thấy
			result++; // tăng biến đếm lên
			str1 = str1.substr(index + lenStr2); // cập nhật lại str1
			index = str1.find(str2); // tìm vị trí kế tiếp
		}
		cout << "Test " << testCount++ << ": " << result << endl;
	}
}