/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class FullName {
public:
	string firstName;
	string lastName;
	string midName;

	void setFirstName(string firstName) {
		this->firstName = firstName;
	}

	void setLastName(string lastName) {
		this->lastName = lastName;
	}

	void setMidName(string midName) {
		this->midName = midName;
	}

	string getFirstName() {
		return firstName;
	}

	string getLastName() {
		return lastName;
	}

	string getMidName() {
		return midName;
	}

	string getFullName() {
		return firstName + " " + lastName + " " + midName;
	}
};

class Address {
public:
	string roadName;
	string number;
	string alley;
	string ward;
	string district;
	string city;
	string nation;

	string getFullAddress();
};

string Address::getFullAddress() {
	return number + ", " + alley + ", " + roadName + ward +
		", " + district + ", " + city + ", " + nation;
}

class Person {
public:
	string id;
	FullName fullName;
	Address address;
	string dateOfBirth;
	string email;
	string phoneNumber;
	string occupation;
	string gender;
	// hành động
	void sleep();
	void eat();
	void work();
	void relax();
};

void Person::sleep() {
	cout << fullName.getFullName() << " is sleeping." << endl;
}

void Person::eat() {
	cout << fullName.getFullName() << " is eating lunch." << endl;
}

void Person::work() {
	cout << fullName.getFullName() << " is working in the garden." << endl;
}

void Person::relax() {
	cout << fullName.getFullName() << " is relaxing by playing with a cat.\n";
}

// nguyên mẫu hàm
void addPersonInfo(Person& person);
void showPersonInfo(Person person);

int main() {
	Person friends[100];
	int size = 0;
	int choice = 0;
	do
	{
		cout << "======================= MENU =======================\n";
		cout << "1. Them moi thong tin nguoi.\n2. Hien thi danh sach.\n";
		cout << "0. Thoat.\nXin moi chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			cout << "<== XIN CHAO VA HEN GAP LAI ==>\n";
			break;
		case 1: {
			addPersonInfo(friends[size++]);
			break;
		}
		case 2: {
			cout << "================ DANH SACH NHAN SU ================\n";
			cout << left << setw(20) << "CMND/CC/HC" << setw(22) << "Ho va ten" 
				<< setw(12) << "Ngay sinh" << setw(25) << "Email" << setw(15) 
				<< "Dia chi" << setw(15) << "So dien thoai" << setw(20)
				<< "Nghe nghiep" << setw(12) << "Gioi tinh" << endl;
			for (int i = 0; i < size; i++)
			{
				showPersonInfo(friends[i]);
			}
			break;
		}
		default:
			cout << "Sai chuc nang. Vui long chon lai!\n";
			break;
		}
	} while (choice != 0);

	return 0;
}

void addPersonInfo(Person& person) {
	cout << "============== NHAP THONG TIN CA NHAN ==============\n";
	cout << "Nhap so CMND/CC/HC: ";
	getline(cin, person.id);
	cout << "Nhap ho: ";
	getline(cin, person.fullName.lastName);
	cout << "Nhap ten dem: ";
	getline(cin, person.fullName.midName);
	cout << "Nhap ten: ";
	getline(cin, person.fullName.firstName);
	cout << "Nhap ngay sinh: ";
	getline(cin, person.dateOfBirth);
	cout << "Nhap email: ";
	getline(cin, person.email);
	cout << "Nhap ten tinh: ";
	getline(cin, person.address.city);
	cout << "Nhap ten quoc gia: ";
	getline(cin, person.address.nation);
	cout << "Nhap so dien thoai: ";
	getline(cin, person.phoneNumber);
	cout << "Nhap nghe nghiep: ";
	getline(cin, person.occupation);
	cout << "Nhap gioi tinh: ";
	getline(cin, person.gender);
}

void showPersonInfo(Person person) {
	cout << left << setw(20) << person.id << setw(22) << person.fullName.getFullName()
		<< setw(12) << person.dateOfBirth << setw(25) << person.email << setw(15)
		<< person.address.city << setw(15) << person.phoneNumber << setw(20)
		<< person.occupation << setw(12) << person.gender << endl;
}