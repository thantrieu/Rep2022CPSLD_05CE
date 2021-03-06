/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <string>
using namespace std;

void showResult(const int testId, const string str, const int k);

int main()
{
    int n; // số bộ test
    string str; // biến lưu chuỗi kí tự
    string kStr; // chuỗi lưu số k
    int k; // số k
    int i = 1;
    cin >> n;
    cin.ignore(); // bỏ qua kí tự còn lại sau khi đọc n
    while (n > 0) {
        getline(cin, str);
        getline(cin, kStr);
        k = stoi(kStr);
        showResult(i, str, k);
        n--;
        i++;
    }
    return 0;
}

void showResult(const int testId, const string str, const int k) {
    cout << "Test " << testId << ": " << endl;
    cout << str.size() << endl;
    if (k >= 0 && k < str.size()) {
        cout << str.at(k) << endl;
    }
    else {
        cout << "INVALID INDEX" << endl;
    }
}