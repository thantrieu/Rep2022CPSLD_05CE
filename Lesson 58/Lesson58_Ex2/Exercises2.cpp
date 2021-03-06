#include <iostream>
#include <iomanip>
#include "Person.h"
using namespace std;

// nguyên mẫu hàm
void addPersonInfo(Person* people, int& size);
void showPersonInfo(const Person& person);
void editPerson(Person& person);
void showTableCollumnName();
int findPersonById(Person* people, const int size, const string id);

int main()
{
	Person people[100];
	int size = 0;
	int choice = 0;
	do
	{
		cout << "======================= MENU =======================\n";
		cout << "1. Them moi nhan su.\n2. Tim nhan su theo ten.\n";
		cout << "3. Sua nghe nghiep theo id.\n4. Hien thi danh sach nhan su.\n";
		cout << "0. Thoat.\nXin moi ban chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			cout << "<== XIN CHAO VA HEN GAP LAI ==>\n";
			break;
		case 1: {
			addPersonInfo(people, size);
			break;
		}
		case 2: {
			if (size > 0) {
				Person results[100];
				int resultCounter = 0;
				string firstName;
				cout << "Nhap ten can tim: ";
				getline(cin, firstName);
				cout << "========================== KET QUA TIM KIEM ==========================\n";
				for (int i = 0; i < size; i++)
				{
					if (people[i].getFullName().getFirstName().compare(firstName) == 0) {
						results[resultCounter++] = people[i];
					}
				}
				if (resultCounter == 0) {
					cout << "<== KHONG CO KET QUA ==>" << endl;
				}
				else {
					showTableCollumnName();
					for (int i = 0; i < resultCounter; i++)
					{
						showPersonInfo(results[i]);
					}
				}
			}
			else {
				cout << "<== DANH SACH RONG. VUI LONG NHAP DU LIEU VAO TRUOC! ==>\n";
			}
			break;
		}
		case 3: {
			if (size > 0) {
				string id;
				cout << "Nhap CMND/CC/HC: ";
				getline(cin, id);
				int index = findPersonById(people, size, id);
				if (index == -1) {
					cout << "<== KHONG TIM THAY KET QUA. VUI LONG THU LAI ==>\n";
				}
				else {
					editPerson(people[index]);
					showTableCollumnName();
					showPersonInfo(people[index]);
				}
			}
			else {
				cout << "<== DANH SACH RONG. VUI LONG NHAP DU LIEU VAO TRUOC! ==>\n";
			}
			break;
		}
		case 4: {
			cout << "================ DANH SACH NHAN SU ================\n";
			if (size > 0) {
				showTableCollumnName();
				for (int i = 0; i < size; i++)
				{
					showPersonInfo(people[i]);
				}
			}
			else {
				cout << "<== DANH SACH RONG. VUI LONG NHAP DU LIEU VAO TRUOC! ==>\n";
			}
			break;
		}
		default:
			cout << "Sai chuc nang. Vui long chon lai!\n";
			break;
		}
	} while (choice != 0);
}

void showTableCollumnName() {
	cout << left << setw(12) << "Ma ban ghi" << setw(20) << "CMND/CC/HC"
		<< setw(22) << "Ho va ten" << setw(12) << "Ngay sinh" << setw(25)
		<< "Email" << setw(15) << "Dia chi" << setw(15) << "So dien thoai"
		<< setw(20) << "Nghe nghiep" << setw(12) << "Gioi tinh" << endl;
}

int findPersonById(Person* people, const int size, const string id) {
	for (int i = 0; i < size; i++)
	{
		if (people[i].getId().compare(id) == 0) {
			return i;
		}
	}
	return -1;
}

// hàm bạn của lớp Person
void addPersonInfo(Person* people, int& size) {
	string city;
	string nation;
	int day, month, year;
	string first, mid, last;
	Person person;
	cout << "============== NHAP THONG TIN NHAN SU ==============\n";
	cout << "Nhap so CMND/CC/HC: ";
	getline(cin, person.id); // gán trực tiếp vào thuộc tính private
	cout << "Nhap ho: ";
	getline(cin, last);
	cout << "Nhap ten dem: ";
	getline(cin, mid);
	cout << "Nhap ten: ";
	getline(cin, first);
	cout << "Nhap ngay sinh: ";
	cin >> day;
	cout << "Nhap thang sinh: ";
	cin >> month;
	cout << "Nhap nam sinh: ";
	cin >> year;
	cout << "Nhap email: ";
	cin.ignore();
	getline(cin, person.email);
	cout << "Nhap ten tinh: ";
	getline(cin, city);
	cout << "Nhap ten quoc gia: ";
	getline(cin, nation);
	cout << "Nhap so dien thoai: ";
	getline(cin, person.phoneNumber);
	cout << "Nhap nghe nghiep: ";
	getline(cin, person.occupation);
	cout << "Nhap gioi tinh: ";
	getline(cin, person.gender);
	Date dob(day, month, year);
	Address address(city, nation);
	FullName fullName(first, last, mid);
	person.dateOfBirth = dob;
	person.address = address;
	person.fullName = fullName;
	people[size++] = person; // thêm person vào mảng
}

// hàm bạn của lớp Person
void editPerson(Person& person) {
	string occupation;
	cout << "Nhap nghe nghiep: ";
	getline(cin, occupation);
	person.occupation = occupation;
	cout << "<== CAP NHAT THANH CONG ==>\n";
}

// hàm bạn của lớp Person
void showPersonInfo(const Person& person) {
	cout << left << setw(12) << person.recordId << setw(20) << person.id
		<< setw(22) << person.fullName.getFullName()
		<< setw(2) << person.dateOfBirth.getDay() << "/"
		<< setw(2) << person.dateOfBirth.getMonth() << "/"
		<< setw(6) << person.dateOfBirth.getYear()
		<< setw(25) << person.email << setw(15)
		<< person.address.getCity() << setw(15) << person.phoneNumber << setw(20)
		<< person.occupation << setw(12) << person.gender << endl;
}