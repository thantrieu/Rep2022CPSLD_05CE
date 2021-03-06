/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void writeToFile(ofstream& ofs, const int testId, const string str, const int k);

int main()
{
    int n; // số bộ test
    string str; // biến lưu chuỗi kí tự
    string kStr; // chuỗi lưu số k
    int k; // số k
    int i = 1;
    ifstream ifs("input6.txt");
    ofstream ofs("output6.txt");
    ifs >> n;
    ifs.ignore(); // bỏ qua kí tự còn lại sau khi đọc n
    while (n > 0) {
        getline(ifs, str);
        getline(ifs, kStr);
        k = stoi(kStr);
        writeToFile(ofs, i, str, k);
        n--;
        i++;
    }
    ifs.close();
    ofs.close();
    return 0;
}

void writeToFile(ofstream& ofs, const int testId, const string str, const int k) {
    ofs << "Test " << testId << ": " << endl;
    int size = str.size();
    ofs << size << endl;
    if (k >= 0 && k < size) {
        ofs << str.at(k) << endl;
    }
    else {
        ofs << "INVALID INDEX" << endl;
    }
}