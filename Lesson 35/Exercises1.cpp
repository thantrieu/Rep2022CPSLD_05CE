/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.04
 *
 */
#include <iostream>

using namespace std;

int main()
{
    char c = 'A';
    long number = 1205L;
    float average = 23.56f;
    bool isFinished = true;
    // con trỏ:
    char* cPtr = &c;
    long* numberPtr = &number;
    float* avgPtr = &average;
    bool* boolPtr = &isFinished;
    // hiện giá trị tại nơi con trỏ đang trỏ tới:
    cout << *cPtr << endl;
    cout << *numberPtr << endl;
    cout << *avgPtr << endl;
    cout << *boolPtr << endl;

    return 0;
}
