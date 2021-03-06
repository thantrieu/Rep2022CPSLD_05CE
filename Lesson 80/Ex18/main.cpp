/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include "Exercises18.hpp"
using namespace std;
using namespace Exercises10;

int main() {
	int choice = 0;
	// khai báo mảng chứa danh sách sinh viên, môn học và bảng điểm
	forward_list<Student> students;
	forward_list<Subject> subjects;
	forward_list<Transcript<Student, Subject>> transcripts;
	// khai báo tên file input/output
	string studentFile = "student.dat";
	string subjectFile = "subject.dat";
	string transcriptFile = "transcript.dat";
	// đọc dữ liệu từ file nhị phân
	readDataFromFile(students, studentFile);
	readDataFromFile(subjects, subjectFile);
	readDataFromFile(transcripts, transcriptFile);
	// menu chương trình
	do {
		cout << "============================== MENU =============================\n";
		cout << "=\t01. Them sinh vien moi vao danh sach.	\t\t=\n";
		cout << "=\t02. Them mon hoc moi vao danh sach.		\t=\n";
		cout << "=\t03. Hien thi danh sach sinh vien.		\t=\n";
		cout << "=\t04. Hien thi danh sach mon hoc.			\t=\n";
		cout << "=\t05. Tim kiem sinh vien trong danh sach.	\t\t=\n";
		cout << "=\t06. Tim kiem mon hoc trong danh sach.		\t=\n";
		cout << "=\t07. Cap nhat thong tin email cho sinh vien.	\t=\n";
		cout << "=\t08. Xoa mot sinh vien khoi danh sach.		\t=\n";
		cout << "=\t09. Xoa mot mon hoc khoi danh sach.		\t=\n";
		cout << "=\t10. Sap xep danh sach sinh vien theo ten a-z.\t\t=\n";
		cout << "=\t11. Sap xep danh sach mon hoc theo ten a-z.	\t=\n";
		cout << "=\t12. Lap bang diem cho sinh vien.		\t=\n";
		cout << "=\t13. Tinh diem trung binh cho cac sinh vien.	\t=\n";
		cout << "=\t14. Sap xep danh sach bang diem theo diem TB giam dan.\t=\n";
		cout << "=\t15. Hien thi danh sach bang diem.	\t\t=\n";
		cout << "=\t16. Ghi thong tin ra file.		\t\t=\n";
		cout << "=\t0. Thoat chuong trinh.			\t\t=\n";
		cout << "=================================================================\n";
		cout << "Nhap lua chon: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 0:
			cout << "============ PHIEN LAM VIEC KET THUC. CAM ON BAN DA SU DUNG DICH VU ============\n";
			break;
		case 1: {
			Student s;
			cin >> s;
			students.push_front(s);
			break;
		}
		case 2: {
			Subject s;
			cin >> s;
			subjects.push_front(s);
			break;
		}
		case 3: {
			if (!students.empty()) {
				cout << "============================= DANH SACH SINH VIEN "
					<< "=============================\n";
				showStudentInfoHeader();
				for (auto i = students.cbegin(); i != students.cend(); i++)
				{
					cout << *i;
				}
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 4: {
			if (!subjects.empty()) {
				cout << "===================== DANH SACH MON HOC "
					<< "======================\n";
				showSubjectInfoHeader();
				for (auto i = subjects.cbegin(); i != subjects.cend(); i++)
				{
					cout << *i;
				}
			}
			else {
				cout << "<== Danh sach mon hoc rong ==>\n";
			}
			break;
		}
		case 5: {
			if (!students.empty()) {
				string id;
				cout << "Nhap ma sinh vien can tim: ";
				cin >> id;
				Student student(id);
				auto foundIndex = findElementById(students, student);
				if (foundIndex == nullptr) {
					cout << "<== Khong tim thay sinh vien ma \"" << id << "\" ==>\n";
				}
				else {
					cout << "<== Tim thay sinh vien ma \"" << id << "\" ==>\n";
					showStudentInfoHeader();
					cout << *foundIndex;
				}
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 6: {
			if (!subjects.empty()) {
				string id;
				cout << "Nhap ma mon hoc can tim: ";
				cin >> id;
				Subject subject(id);
				auto foundIndex = findElementById(subjects, subject);
				if (foundIndex == nullptr) {
					cout << "<== Khong tim thay mon hoc ma \"" << id << "\" ==>\n";
				}
				else {
					cout << "<== Tim thay mon hoc ma \"" << id << "\" ==>\n";
					showSubjectInfoHeader();
					cout << *foundIndex;
				}
			}
			else {
				cout << "<== Danh sach mon hoc rong ==>\n";
			}
			break;
		}
		case 7: {
			if (!students.empty()) {
				string id;
				cout << "Nhap ma sinh vien can cap nhat email: ";
				cin >> id;
				Student student(id);
				auto foundIndex = findElementById(students, student);
				if (foundIndex == nullptr) {
					cout << "<== Khong tim thay sinh vien ma \"" << id << "\" ==>\n";
				}
				else {
					cout << "Nhap email moi: ";
					string email;
					cin >> email;
					(*foundIndex).setEmail(email);
					cout << "<== Cap nhat email thanh cong ==>\n";
				}
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 8: {
			if (!students.empty()) {
				string id;
				cout << "Nhap ma sinh vien can xoa: ";
				cin >> id;
				Student student(id);
				bool isRemoved = removeElement(students, student);
				if (!isRemoved) {
					cout << "<== Khong tim thay sinh vien ma \"" << id << "\" ==>\n";
				}
				else {
					cout << "<== Xoa sinh vien thanh cong ==>\n";
				}
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 9: {
			if (!subjects.empty()) {
				string id;
				cout << "Nhap ma mon hoc can xoa: ";
				cin >> id;
				Subject subject(id);
				bool isRemoved = removeElement(subjects, subject);
				if (!isRemoved) {
					cout << "<== Khong tim thay mon hoc ma \"" << id << "\" ==>\n";
				}
				else {
					cout << "<== Xoa mon hoc thanh cong ==>\n";
				}
			}
			else {
				cout << "<== Danh sach mon hoc rong ==>\n";
			}
			break;
		}
		case 10: {
			if (!students.empty()) {
				students.sort(comparator<Student>);
				cout << "<== Sap xep danh sach sinh vien hoan tat ==>\n";
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 11: {
			if (!subjects.empty()) {
				subjects.sort(comparator<Subject>);
				cout << "<== Sap xep danh sach mon hoc hoan tat ==>\n";
			}
			else {
				cout << "<== Danh sach mon hoc rong ==>\n";
			}
			break;
		}
		case 12: {
			if (!students.empty()) {
				string studentId;
				string subjectId;
				cout << "Nhap ma sinh vien: ";
				cin >> studentId;
				cout << "Nhap ma mon hoc: ";
				cin >> subjectId;
				bool isRecordExisted = isTranscriptExisted(transcripts, studentId, subjectId);
				if (isRecordExisted) { // kiểm tra xem sinh viên x với môn học y đã tồn tại trong danh sách bảng điểm chưa
					cout << "<== Thong tin bang diem mon hoc ma \"" << subjectId 
						<< "\" cua sinh vien ma \"" << studentId << "\" da ton tai ==>\n";
				}
				else {
					Student student(studentId);
					auto studentIndex = findElementById(students, student);
					if (studentIndex == nullptr) {
						cout << "<== Khong ton tai sinh vien can tim ==>\n";
					}
					else { // đảm bảo sinh viên với mã nhập vào phải tồn tại trước
						Subject sub(subjectId);
						auto subjectIndex = findElementById(subjects, sub);
						if (subjectIndex == nullptr) {
							cout << "<== Khong tim thay mon hoc can tim ==>\n";
						}
						else { // đảm bảo cả môn học nhập vào phải tồn tại trước
							student = *studentIndex;
							sub = *subjectIndex;
							Transcript<Student, Subject> tran(student, sub);
							cin >> tran;
							transcripts.push_front(tran);
						}
					}
				}
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 13: {
			if (!transcripts.empty()) {
				// tính điểm tb cần phải dùng iterator thay vì const_iterator nên ta gọi begin thay vì cbegin
				for (auto i = transcripts.begin(); i != transcripts.end(); i++)
				{
					(*i).calculateGpa();
				}
				cout << "<== Tinh diem trung binh cho sinh vien trong danh sach hoan tat ==>\n";
			}
			else {
				cout << "<== Danh sach bang diem rong ==>\n";
			}
			break;
		}
		case 14: {
			if (!transcripts.empty()) {				
				transcripts.sort(transcriptComparator);
				cout << "<== Sap xep danh sach bang diem hoan tat ==>\n";
			}
			else {
				cout << "<== Danh sach bang diem rong ==>\n";
			}
			break;
		}
		case 15: {
			if (!transcripts.empty()) {
				cout << "=========================================="
					<< " DANH SACH BANG DIEM SINH VIEN "
					<< "==========================================\n";
				showTranscriptInfoHeader();
				for (auto i = transcripts.cbegin(); i != transcripts.cend(); i++)
				{
					cout << *i;
				}
			}
			else {
				cout << "<== Danh sach bang diem rong ==>\n";
			}
			break;
		}
		case 16: {
			if (!students.empty()) {
				saveToFile(students, studentFile);
				cout << "<== Ghi file sinh vien hoan tat ==>\n";
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			if (!subjects.empty()) {
				saveToFile(subjects, subjectFile);
				cout << "<== Ghi file mon hoc hoan tat ==>\n";
			}
			else {
				cout << "<== Danh sach mon hoc rong ==>\n";
			}
			if (!transcripts.empty()) {
				saveToFile(transcripts, transcriptFile);
				cout << "<== Ghi file bang diem hoan tat ==>\n";
			}
			else {
				cout << "<== Danh sach bang diem rong ==>\n";
			}
			break;
		}
		default:
			cout << "SAI CHUC NANG, VUI LONG KIEM TRA LAI\n";
			break;
		}
	} while (choice != 0);

	return 0;
}
