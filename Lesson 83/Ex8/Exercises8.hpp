/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.06
 *
 */

#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <set>	// sử dụng set
#include "Subject.hpp"
#include "Transcript.hpp"
#include "Student.hpp"
using namespace std;

namespace Exercises8 {

	class CmpClass {
	public:
		bool operator() (Transcript<Student, Subject> const& a,
			Transcript<Student, Subject> const& b) const {
			return a > b;
		}
	};

	void showStudentInfoHeader() {
		cout << left << setw(15) << "Ma SV" << setw(25) << "Ho va ten"
			<< setw(25) << "Email" << setw(20) << "So dien thoai" << endl;
	}
	
	void showSubjectInfoHeader() {
		cout << left << setw(15) << "Ma mon" << setw(30) << "Ten mon"
			<< setw(10) << "So tiet" << setw(10) << "So tin" << endl;
	}

	template<class T> const T* findElementById(set<T>& set, const T& t) {
		for (auto i = set.begin(); i != set.end(); i++)
		{
			if (*i == t) {
				return &(*i);
			}
		}
		return nullptr;
	}

	template<class T> bool removeElement(set<T>& set, const T& t) {
		for (auto i = set.cbegin(); i != set.cend(); i++)
		{
			if (*i == t) {
				set.erase(i); 
				return true; // xoa thanh cong
			}
		}
		return false; // xoa that bai
	}

	bool isTranscriptExisted(const set<Transcript<Student, Subject>>& set, 
		const string studentId, const string subjectId) {
		Student student(studentId);
		Subject subject(subjectId);
		for (auto i = set.cbegin(); i != set.cend(); i++)
		{
			if (i->getStudent() == student && i->getSubject() == subject) {
				return true;
			}
		}
		return false;
	}

	void showTranscriptInfoHeader() {
		cout << left << setw(15) << "Ma SV" << setw(25) << "Ho va ten"
			<< setw(15) << "Ma mon" << setw(25) << "Ten mon hoc"
			<< setw(10) << "Diem he 1" << setw(10) << "Diem he 2" << setw(10)
			<< "Diem he 3" << setw(10) << "GPA" << endl;
	}

	template<class T> void saveToFile(const set<T>& set, const string fileName) {
		ofstream ofs(fileName, ios::out | ios::binary);
		if (ofs) {
			for (auto i = set.cbegin(); i != set.cend(); i++)
			{
				ofs.write(reinterpret_cast<const char*>(&(*i)), sizeof(T));
			}
			ofs.close();
		}
	}

	void saveTranscriptToFile(const set<Transcript<Student, Subject>, CmpClass>& set, 
		const string fileName) {
		ofstream ofs(fileName, ios::out | ios::binary);
		if (ofs) {
			for (auto i = set.cbegin(); i != set.cend(); i++)
			{
				ofs.write(reinterpret_cast<const char*>(&(*i)), sizeof(Transcript<Student, Subject>));
			}
			ofs.close();
		}
	}

	template<class T> void readDataFromFile(set<T>& set, const string fileName) {
		ifstream ifs(fileName, ios::in | ios::binary);
		if (ifs) {
			while (!ifs.eof()) {
				T object;
				ifs.read(reinterpret_cast<char*>(&object), sizeof(T));
				if (ifs.eof()) {
					break;
				}
				else {
					set.insert(object);
				}
			}
			ifs.close();
		}
	}

	void readTranscriptFromFile(set<Transcript<Student, Subject>, CmpClass>& set, const string fileName) {
		ifstream ifs(fileName, ios::in | ios::binary);
		if (ifs) {
			while (!ifs.eof()) {
				Transcript<Student, Subject> object;
				ifs.read(reinterpret_cast<char*>(&object), sizeof(Transcript<Student, Subject>));
				if (ifs.eof()) {
					break;
				}
				else {
					set.insert(object);
				}
			}
			ifs.close();
		}
	}

	template<class T> bool comparator(const T& a, const T& b) {
		return a < b;
	}

	// hàm định nghĩa cách thức sắp xếp các đối tượng của bảng điểm
	bool transcriptComparator(
		const Transcript<Student, Subject>& t1, 
		const Transcript<Student, Subject>& t2) {
		if (t1.getGpa() != t2.getGpa()) {
			return t1.getGpa() > t2.getGpa();
		}
		else { // điểm trùng nhau
			if (t1.getStudent().getFirstName() // nếu tên trùng nhau: xếp theo họ a-z
				.compare(t2.getStudent().getFirstName()) == 0) {
				return t1.getStudent().getLastName()
					.compare(t2.getStudent().getLastName()) < 0;
			}
			else {// xếp theo tên a-z
				return t1.getStudent().getFirstName()
					.compare(t2.getStudent().getFirstName()) < 0;
			}
		}
		
	}
}