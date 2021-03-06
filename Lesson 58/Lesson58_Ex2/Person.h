#pragma once
#include <string>
#include "Address.h"
#include "FullName.h"
#include "Date.h"

using namespace std;

class Person
{
private:
	friend void addPersonInfo(Person* people, int& size);
	friend void showPersonInfo(const Person& person);
	friend void editPerson(Person& person);
	static int autoIncrementId; // 
	int recordId; // id dùng riêng cho từng đối tượng
	string id;
	FullName fullName;
	Address address;
	Date dateOfBirth;
	string email;
	string phoneNumber;
	string occupation;
	string gender;
public:
	// hàm khởi tạo
	Person();
	Person(const string id);
	Person(const string id, const FullName& fullName, 
		const Address& address, const Date dob,
		const string email, const string phoneNum, 
		const string occupation, const string gender);
	//getter and setter
	int getRecordId() const;
	void setRecordId(const int recordId);
	void setId(const string id);
	string getId() const;
	void setAddress(const Address& address);
	Address getAddress() const;
	void setFullName(const FullName& fullName);
	FullName getFullName() const;
	void setDateOfBirth(const Date dateOfBirth);
	Date getDateOfBirth() const;
	void setEmail(const string email);
	string getEmail() const;
	void setPhoneNumber(const string phoneNumber);
	string getPhoneNumber() const;
	void setOccupation(const string occupation);
	string getOccpation() const;
	void setGender(const string gender);
	string getGender() const;
	// hành động
	void sleep();
	void eat();
	void work();
	void relax();
};

