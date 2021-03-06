/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string upperCaseString(string str);
string lowerCaseString(string str);

int main()
{
    int n; // số bộ test
    string str; // biến lưu chuỗi kí tự
    int i = 1;
    ifstream ifs("input7.txt");
    ofstream ofs("output7.txt");
    ifs >> n;
    ifs.ignore(); // bỏ qua kí tự còn lại sau khi đọc n
    while (i <= n) {
        getline(ifs, str);
        ofs << "Test " << i << ": " << endl;
        ofs << upperCaseString(str) << endl;
        ofs << lowerCaseString(str) << endl;
        i++;
    }
    ofs.close();
    ifs.close();
    return 0;
}
// mã của chữ hoa chữ thường cách nhau 32 đơn vị('a' == 97, 'A' == 65)
// trong bảng mã ASCII
string upperCaseString(string str) {
    for (size_t i = 0; i < str.size(); i++)
    {
        char c = str.at(i);
        if (c >= 'a' && c <= 'z') { // nếu c là kí tự chữ thường
            c = c - 32; // viết hoa nó lên
            str.at(i) = c;
        }
    }
    return str;
}

string lowerCaseString(string str) {
    for (size_t i = 0; i < str.size(); i++)
    {
        char c = str.at(i);
        if (c >= 'A' && c <= 'Z') { // c là chữ cái hoa
            c = c + 32; // viết thường nó
            str.at(i) = c;
        }
    }
    return str;
}