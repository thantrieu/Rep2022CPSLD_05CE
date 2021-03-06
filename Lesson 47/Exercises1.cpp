#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define SIZE = 100;

typedef struct {
	string id;
	string fullName;
	string major;
	int age;
	float gpa;
} Student;

void showInfo(const Student s) {
	cout << left << setw(15) << s.id << setw(25) << s.fullName
		<< setw(25) << s.major << setw(12) << s.age << setw(12) << s.gpa << endl;
}

void getUserInfo(Student& s) {
	cout << "Ma sinh vien: ";
	getline(cin, s.id); // truy cập biến struct thông thường
	cout << "Ho va ten: ";
	getline(cin, s.fullName);
	cout << "Chuyen nganh: ";
	getline(cin, s.major);
	cout << "Tuoi: ";
	cin >> s.age;
	cout << "Diem TB: ";
	cin >> s.gpa;
	cin.ignore();
}

void sortByGpa(Student* students, const int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (students[j].gpa > students[j - 1].gpa) {
				swap(students[j], students[j - 1]);
			}
		}
	}
}

float findMaxGpa(Student* students, const int n) {
	float maxGpa = students[0].gpa;
	for (int i = 1; i < n; i++)
	{
		if (students[i].gpa > maxGpa) {
			maxGpa = students[i].gpa;
		}
	}
	return maxGpa;
}

void showHeader() {
	cout << left << setw(15) << "Ma SV" << setw(25) << "Ho va ten"
		<< setw(25) << "Chuyen nganh" << setw(12) << "Tuoi" 
		<< setw(12) << "Diem TB" << endl;
}

void removeAt(Student* students, int& n, const int k) {
	for (int i = k; i < n - 1; i++)
	{
		students[i] = students[i + 1];
	}
	n--;
}

int main() {
	int n = 0;
	Student* students = new Student[100];
	int choice;
	do {
		cout << "=================== MENU ===================\n";
		cout << "1. Them moi sinh vien.\n";
		cout << "2. Sap xep danh sach sinh vien giam dan theo diem.\n";
		cout << "3. Hien thi danh sach sinh vien hien co.\n";
		cout << "4. Tim tat ca cac sinh vien co diem cao nhat.\n";
		cout << "5. Xoa mot sinh vien khoi danh sach theo ma.\n";
		cout << "Ban chon?\n";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 0:
			cout << "<== Cam on ban da su dung dich vu ==>\n";
			break;
		case 1: {
			Student student;
			getUserInfo(student);
			students[n++] = student;
			break;
		}
		case 2: {
			if (n > 0) {
				sortByGpa(students, n);
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 3: {
			if (n > 0) {
				showHeader();
				for (int i = 0; i < n; i++)
				{
					showInfo(students[i]);
				}
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 4: {
			if (n > 0) {
				float maxGpa = findMaxGpa(students, n);
				showHeader();
				for (int i = 0; i < n; i++)
				{
					if (students[i].gpa == maxGpa) {
						showInfo(students[i]);
					}
				}
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 5: {
			if (n > 0) {
				bool isSuccess = false;
				string id;
				cout << "Nhap ma sinh vien can xoa: ";
				getline(cin, id);
				for (int i = 0; i < n; i++)
				{
					if (students[i].id.compare(id) == 0) {
						removeAt(students, n, i);
						i--;
						isSuccess = true; // đánh dấu là xóa sv thành công
					}
				}
				if (isSuccess) {
					cout << "<== Xoa sinh vien thanh cong ==>\n";
				}
				else {
					cout << "<== Khong tim thay sinh vien de xoa ==>\n";
				}
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		default:
			cout << "Nhap sai chuc nang. Vui long kiem tra lai.\n";
			break;
		}
	} while (choice != 0);
	delete[] students;
	return 0;
}