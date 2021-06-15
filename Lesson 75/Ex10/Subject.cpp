//
//  Subject.cpp
//  Lesson75Exercises10
//
//  Created by Branium on 14/06/2021.
//

#include <iomanip>
#include "Subject.hpp"
using namespace std;

Subject::Subject(std::string id, std::string name, int lesson, int credit) : lesson(lesson), credit(credit) {
    setId(id);
    setName(name);
}

void Subject::setId(std::string id) {
    int len = (int)id.length();
    len = len > 20 ? 19: len;
    id.copy(this->id, len);
    this->id[len] = '\0';
}

void Subject::setName(std::string name) {
    int len = (int)name.length();
    len = len > 40 ? 39 : len;
    name.copy(this->name, len);
    this->name[len] = '\0';
}

ostream& operator << (ostream& os, const Subject& subject) {
    os << setw(15) << subject.id << setw(30) << subject.name
       << setw(10) << subject.lesson << setw(10) << subject.credit << endl;
    return os;
}

istream& operator >> (istream& is, Subject& subject) {
    cout << "Ma mon hoc: ";
    is.getline(subject.id, 20);
    cout << "Ten mon hoc: ";
    is.getline(subject.name, 40);
    cout << "So tiet hoc: ";
    is >> subject.lesson;
    cout << "So tin chi: ";
    is >> subject.credit;
    return is;
}