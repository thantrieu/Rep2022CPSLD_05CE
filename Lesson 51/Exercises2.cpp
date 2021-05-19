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
private:
	string firstName;
	string lastName;
	string midName;
public:
	// hàm khởi tạo
	FullName() {}
	FullName(string firstName) : firstName(firstName) {}
	FullName(string firstName, string lastName) :
		firstName(firstName), lastName(lastName) {}
	FullName(string firstName, string lastName, string midName) :
		firstName(firstName), lastName(lastName), midName(midName) {}

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
private:
	string roadName;
	string number;
	string alley;
	string ward;
	string district;
	string city;
	string nation;
public:
	// hàm khởi tạo
	Address() {}
	Address(string city) : city(city) {}
	Address(string city, string nation) : city(city), nation(nation) {}
	Address(string district, string city, string nation) :
		district(district), city(city), nation(nation) {}
	string getFullAddress();
	void setCity(string city) { this->city = city; }
	string getCity() { return city; }
	void setNation(string nation) { this->nation = nation; }
	string getNation() { return nation; }
	void setRoadName(string roadName) { this->roadName = roadName; }
	string getRoadName() { return roadName; }
	void setNumber(string number) { this->number = number; }
	string getNumber() { return number; }
	void setAlley(string alley) { this->alley = alley; }
	string getAlley() { return alley; }
	void setWard(string ward) { this->ward = ward; }
	string getWard() { return ward; }
	void setDistrict(string district) { this->district = district; }
	string getDistrict() { return district; }
};

string Address::getFullAddress() {
	return number + ", " + alley + ", " + roadName + ward +
		", " + district + ", " + city + ", " + nation;
}

class Person {
private:
	string id;
	FullName fullName;
	Address address;
	string dateOfBirth;
	string email;
	string phoneNumber;
	string occupation;
	string gender;
public:
	// hàm khởi tạo
	Person() {}
	Person(string id) : id(id) {}
	Person(FullName fullName) : fullName(fullName) {}
	Person(string id, FullName fullName) : id(id), fullName(fullName) {}
	Person(string id, FullName fullName, string gender) :
		id(id), fullName(fullName), gender(gender) {}
	Person(string id, FullName fullName, Address address, string dob,
		string email, string phoneNum, string occupation, string gender) :
		id(id), fullName(fullName), address(address), dateOfBirth(dob),
		email(email), phoneNumber(phoneNum), occupation(occupation), gender(gender) {}
	//getter and setter
	void setId(string id) { this->id = id; }
	string getId() { return id; }
	void setAddress(Address address) { this->address = address; }
	Address getAddress() { return address; }
	void setFullName(FullName fullName) { this->fullName = fullName; }
	FullName getFullName() { return fullName; }
	void setDateOfBirth(string dateOfBirth) { this->dateOfBirth = dateOfBirth; }
	string getDateOfBirth() { return dateOfBirth; }
	void setEmail(string email) { this->email = email; }
	string getEmail() { return email; }
	void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
	string getPhoneNumber() { return phoneNumber; }
	void setOccupation(string occupation) { this->occupation = occupation; }
	string getOccpation() { return occupation; }
	void setGender(string gender) { this->gender = gender; }
	string getGender() { return gender; }

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
Person addPersonInfo();
void showPersonInfo(Person person);
void showTableCollumnName();
Person* findPersonById(Person* people, const int size, string id);

int main() {
	Person friends[100];
	int size = 0;
	int choice = 0;
	do
	{
		cout << "======================= MENU =======================\n";
		cout << "1. Them moi thong tin nguoi.\n2. Hien thi danh sach.\n";
		cout << "3. Tim nhan su theo ten.\n4. Sua nghe nghiep theo CC/HC.\n";
		cout << "0. Thoat.\nXin moi chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			cout << "<== XIN CHAO VA HEN GAP LAI ==>\n";
			break;
		case 1: {
			friends[size++] = addPersonInfo();
			break;
		}
		case 2: {
			cout << "================ DANH SACH NHAN SU ================\n";
			if (size > 0) {
				showTableCollumnName();
				for (int i = 0; i < size; i++)
				{
					showPersonInfo(friends[i]);
				}
			}
			else {
				cout << "<== DANH SACH RONG. VUI LONG NHAP DU LIEU VAO TRUOC! ==>\n";
			}
			break;
		}
		case 3: {
			if (size > 0) {
				Person results[100];
				int resultCounter = 0;
				string firstName;
				cout << "Nhap ten can tim: ";
				getline(cin, firstName);
				cout << "========================== KET QUA TIM KIEM ==========================\n";
				for (int i = 0; i < size; i++)
				{
					if (friends[i].getFullName().getFirstName().compare(firstName) == 0) {
						results[resultCounter++] = friends[i];
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
		case 4: {
			if (size > 0) {
				string id;
				cout << "Nhap CMND/CC/HC: ";
				getline(cin, id);
				Person* person = findPersonById(friends, size, id);
				if (person == nullptr) {
					cout << "<== KHONG TIM THAY KET QUA. VUI LONG THU LAI ==>\n";
				}
				else {
					string occupation;
					cout << "Nhap nghe nghiep: ";
					getline(cin, occupation);
					person->setOccupation(occupation);
					cout << "<== CAP NHAT THANH CONG ==>\n";
					showTableCollumnName();
					showPersonInfo(*person);
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

	return 0;
}

void showTableCollumnName() {
	cout << left << setw(20) << "CMND/CC/HC" << setw(22) << "Ho va ten"
		<< setw(12) << "Ngay sinh" << setw(25) << "Email" << setw(15)
		<< "Dia chi" << setw(15) << "So dien thoai" << setw(20)
		<< "Nghe nghiep" << setw(12) << "Gioi tinh" << endl;
}

Person* findPersonById(Person* people, const int size, string id) {
	for (int i = 0; i < size; i++)
	{
		if (people[i].getId().compare(id) == 0) {
			return &people[i];
		}
	}
	return nullptr;
}

Person addPersonInfo() {
	string personId;
	string firstName;
	string lastName;
	string midName;
	string dob;
	string email;
	string city;
	string nation;
	string phoneNumber;
	string occupation;
	string gender;
	cout << "============== NHAP THONG TIN CA NHAN ==============\n";
	cout << "Nhap so CMND/CC/HC: ";
	getline(cin, personId);
	cout << "Nhap ho: ";
	getline(cin, lastName);
	cout << "Nhap ten dem: ";
	getline(cin, midName);
	cout << "Nhap ten: ";
	getline(cin, firstName);
	cout << "Nhap ngay sinh: ";
	getline(cin, dob);
	cout << "Nhap email: ";
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
	Address address(city, nation);
	FullName fullName(firstName, lastName, midName);
	Person person(personId, fullName, address,
		dob, email, phoneNumber, occupation, gender);
	return person;
}

void showPersonInfo(Person person) {
	cout << left << setw(20) << person.getId() << setw(22) << person.getFullName().getFullName()
		<< setw(12) << person.getDateOfBirth() << setw(25) << person.getEmail() << setw(15)
		<< person.getAddress().getCity() << setw(15) << person.getPhoneNumber() << setw(20)
		<< person.getOccpation() << setw(12) << person.getGender() << endl;
}