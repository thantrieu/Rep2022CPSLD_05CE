/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void showResult(const int testId, const string str, const int k);

int main()
{
    int n; // số bộ test
    string str; // biến lưu chuỗi kí tự
    string kStr; // chuỗi lưu số k
    int k; // số k
    int i = 1;
    ifstream ifs("input6.txt");
    ifs >> n;
    ifs.ignore(); // bỏ qua kí tự còn lại sau khi đọc n
    while (n > 0) {
        getline(ifs, str);
        getline(ifs, kStr);
        k = stoi(kStr);
        showResult(i, str, k);
        n--;
        i++;
    }
    ifs.close();
    return 0;
}

void showResult(const int testId, const string str, const int k) {
    cout << "Test " << testId << ": " << endl;
    int size = str.size();
    cout << size << endl;
    if (k >= 0 && k < size) {
        cout << str.at(k) << endl;
    }
    else {
        cout << "INVALID INDEX" << endl;
    }
}