/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <iomanip>
using namespace std;

// hàm nhập liệu
void getInputFromKeyboard(char* fullName, int& age, 
	 char* address, char* phoneNumber, char* occ) {
	cout << "Ho va ten: ";
	cin.getline(fullName, 40); 
	cout << "Tuoi: ";
	cin >> age;
	cin.ignore(); // đọc bỏ kí tự thừa
	cout << "Address: ";
	cin.getline(address, 40);
	cout << "Phone number: ";
	cin.getline(phoneNumber, 11); // số đt chỉ có 10 kí tự
	cout << "Nghe nghiep: ";
	cin.getline(occ, 40);
}

// hàm hiển thị kết quả
void showInfo(const char* fullName, const int age,
	const char* address, const char* phoneNumber, const char* occ) {
	cout << left << setw(25) << "Ho ten" << setw(10)
		<< "Tuoi" << setw(20) << "Dia chi" << setw(15) << "So dien thoai"
		<< setw(30) << "Nghe nghiep" << endl;
	cout << left << setw(25) << fullName << setw(10)
		<< age << setw(20) << address << setw(15) << phoneNumber
		<< setw(30) << occ << endl;
}

int main()
{
	// khai báo biến
	char fullName[40];
	int age;
	char address[40];
	char phoneNumber[12];
	char occupation[40];
	// nhập dữ liệu
	getInputFromKeyboard(fullName, age, address, phoneNumber, occupation);
	// hiển thị
	showInfo(fullName, age, address, phoneNumber, occupation);
	return 0;
}
