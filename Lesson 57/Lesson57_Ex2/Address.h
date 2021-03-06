#pragma once
#include<string>
using namespace std;

class Address
{
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
	Address();
	Address(const string city);
	Address(const string city, const string nation);
	Address(const string district, const string city, const string nation);
	string getFullAddress() const;
	void setCity(const string city);
	string getCity() const;
	void setNation(const string nation);
	string getNation() const;
	void setRoadName(const string roadName);
	string getRoadName() const;
	void setNumber(const string number);
	string getNumber() const;
	void setAlley(const string alley);
	string getAlley() const;
	void setWard(const string ward);
	string getWard() const;
	void setDistrict(const string district);
	string getDistrict() const;
};

