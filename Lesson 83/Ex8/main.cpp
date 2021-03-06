/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#include "Exercises8.hpp"
using namespace std;
using namespace Exercises8;

int main() {
	int choice = 0;
	// khai báo mảng chứa danh sách sinh viên, môn học và bảng điểm
	set<Student> students;
	set<Subject> subjects;
	set<Transcript<Student, Subject>, CmpClass> transcripts;
	// khai báo tên file input/output
	string studentFile = "student.dat";
	string subjectFile = "subject.dat";
	string transcriptFile = "transcript.dat";
	// đọc dữ liệu từ file nhị phân
	readDataFromFile(students, studentFile);
	readDataFromFile(subjects, subjectFile);
	readTranscriptFromFile(transcripts, transcriptFile);
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
		cout << "=\t10. Lap bang diem cho sinh vien.		\t=\n";
		cout << "=\t11. Hien thi danh sach bang diem.	\t\t=\n";
		cout << "=\t12. Ghi thong tin ra file.		\t\t=\n";
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
			if (find(students.begin(), students.end(), s) != students.end()) {
				 // sinh viên đã tồn tại trong set
				cout << "<== Sinh vien da ton tai trong set ==>\n";
			}
			else { // sinh viên chưa tồn tại trong set
				students.insert(s);
			}
			break;
		}
		case 2: {
			Subject s;
			cin >> s;
			if (find(subjects.begin(), subjects.end(), s) != subjects.end()) {
				// môn học đã tồn tại trong set
				cout << "<== Mon hoc da ton tai trong set ==>\n";
			}
			else { // môn học chưa tồn tại trong set
				subjects.insert(s);
			}
			break;
		}
		case 3: {
			if (!students.empty()) {
				cout << "============================= DANH SACH SINH VIEN "
					<< "=============================\n";
				showStudentInfoHeader();
				for (auto& s: students)
				{
					cout << s;
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
				for (auto & s: subjects)
				{
					cout << s;
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
				auto foundStudent = findElementById(students, student);
				if (foundStudent == nullptr) {
					cout << "<== Khong tim thay sinh vien ma \"" << id << "\" ==>\n";
				}
				else {
					// tạo đối tượng sinh viên mới từ thông tin đã có
					Student student; 
					student.setId(foundStudent->getId());
					student.setFirstName(foundStudent->getFirstName());
					student.setMidName(foundStudent->getMidname());
					student.setLastName(foundStudent->getLastName());
					student.setPhoneNumber(foundStudent->getPhoneNumber());
					cout << "Nhap email moi: ";
					string email;
					cin >> email;
					student.setEmail(email); // cập nhật lại mail
					students.erase(*foundStudent); // xóa sinh viên này khỏi set
					students.insert(student); // chèn lại sinh viên sau khi cập nhật vào danh sách
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
				string studentId;
				string subjectId;
				cout << "Nhap ma sinh vien: ";
				cin >> studentId;
				cout << "Nhap ma mon hoc: ";
				cin >> subjectId;
				Subject subject(subjectId);
				Student student(studentId);
				Transcript<Student, Subject> trans(student, subject);
				auto result = find(transcripts.begin(), transcripts.end(), trans);
				bool isRecordExisted = result != transcripts.end() ? true : false;
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
							tran.calculateGpa(); // tính điểm tb môn
							transcripts.insert(tran);
						}
					}
				}
			}
			else {
				cout << "<== Danh sach sinh vien rong ==>\n";
			}
			break;
		}
		case 11: {
			if (!transcripts.empty()) {
				cout << "=========================================="
					<< " DANH SACH BANG DIEM SINH VIEN "
					<< "==========================================\n";
				showTranscriptInfoHeader();
				for (auto& t : transcripts)
				{
					cout << t;
				}
			}
			else {
				cout << "<== Danh sach bang diem rong ==>\n";
			}
			break;
		}
		case 12: {
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
				saveTranscriptToFile(transcripts, transcriptFile);
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
