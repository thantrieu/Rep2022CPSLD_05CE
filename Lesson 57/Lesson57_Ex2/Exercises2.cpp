#include <iostream>
#include <iomanip>
#include "Person.h"
using namespace std;

// nguyên mẫu hàm
Person addPersonInfo();
void showPersonInfo(const Person& person);
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
			people[size++] = addPersonInfo();
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
					string occupation;
					cout << "Nhap nghe nghiep: ";
					getline(cin, occupation);
					people[index].setOccupation(occupation);
					cout << "<== CAP NHAT THANH CONG ==>\n";
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

Person addPersonInfo() {
	string personId;
	string firstName;
	string lastName;
	string midName;
	string email;
	string city;
	string nation;
	string phoneNumber;
	string occupation;
	string gender;
	int day, month, year;
	cout << "============== NHAP THONG TIN NHAN SU ==============\n";
	cout << "Nhap so CMND/CC/HC: ";
	getline(cin, personId);
	cout << "Nhap ho: ";
	getline(cin, lastName);
	cout << "Nhap ten dem: ";
	getline(cin, midName);
	cout << "Nhap ten: ";
	getline(cin, firstName);
	cout << "Nhap ngay sinh: ";
	cin >> day;
	cout << "Nhap thang sinh: ";
	cin >> month;
	cout << "Nhap nam sinh: ";
	cin >> year;
	cout << "Nhap email: ";
	cin.ignore();
	getline(cin, email);
	cout << "Nhap ten tinh: ";
	getline(cin, city);
	cout << "Nhap ten quoc gia: ";
	getline(cin, nation);
	cout << "Nhap so dien thoai: ";
	getline(cin, phoneNumber);
	cout << "Nhap nghe nghiep: ";
	getline(cin, occupation);
	cout << "Nhap gioi tinh: ";
	getline(cin, gender);
	Date dob(day, month, year);
	Address address(city, nation);
	FullName fullName(firstName, lastName, midName);
	Person person(personId, fullName, address,
		dob, email, phoneNumber, occupation, gender);
	return person;
}

void showPersonInfo(const Person& person) {
	cout << left << setw(12) << person.getRecordId() << setw(20) << person.getId()
		<< setw(22) << person.getFullName().getFullName()
		<< setw(2) << person.getDateOfBirth().getDay() << "/"
		<< setw(2) << person.getDateOfBirth().getMonth() << "/"
		<< setw(6) << person.getDateOfBirth().getYear()
		<< setw(25) << person.getEmail() << setw(15)
		<< person.getAddress().getCity() << setw(15) << person.getPhoneNumber() << setw(20)
		<< person.getOccpation() << setw(12) << person.getGender() << endl;
}