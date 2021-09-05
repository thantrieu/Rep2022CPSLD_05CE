#include <iostream>

using namespace std;

#define NUMBER_OF_ZODIAC 12

struct zodiac {
    int startDay;
    int startMonth;
    int endMonth;
    int endDay;
    string name;
};

typedef struct zodiac Zodiac;

Zodiac createZodiac(int startMonth, int startDay, int endMonth, int endDay, string name) {
    Zodiac zodiac;
    zodiac.startDay = startDay;
    zodiac.startMonth = startMonth;
    zodiac.endDay = endDay;
    zodiac.endMonth = endMonth;
    zodiac.name = name;
    return zodiac;
}

void init(Zodiac* zodiacs) {
    zodiacs[0] = createZodiac(1, 20, 2, 18, "Bao Binh");
    zodiacs[1] = createZodiac(2, 19, 3, 20, "Song ngu");
    zodiacs[2] = createZodiac(3, 21, 4, 20, "Bach Duong");
    zodiacs[3] = createZodiac(4, 21, 5, 20, "Kim Nguu");
    zodiacs[4] = createZodiac(5, 21, 6, 21, "Song Tu");
    zodiacs[5] = createZodiac(6, 22, 7, 27, "Cu Giai");
    zodiacs[6] = createZodiac(7, 23, 8, 22, "Su Tu");
    zodiacs[7] = createZodiac(8, 23, 9, 22, "Xu Nu");
    zodiacs[8] = createZodiac(9, 23, 10, 23, "Thien Binh");
    zodiacs[9] = createZodiac(10, 24, 11, 22, "Bo Cap");
    zodiacs[10] = createZodiac(11, 23, 12, 21, "Nhan Ma");
    zodiacs[11] = createZodiac(12, 22, 1, 19, "Ma Ket");
}

string findZodiac(Zodiac* zodiacs, int month, int day) {
    if (zodiacs[month - 1].startDay <= day) {
        return zodiacs[month - 1].name;
    }
    month--;
    if (month < 1) {
        month = 12;
    }
    if (zodiacs[month - 1].endDay >= day) {
        return zodiacs[month - 1].name;
    }
    return "";
}

bool validDay(int month, int day) {
    int dayOfMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > 0 && day <= dayOfMonths[month]) {
        return true;
    }
    return false;
}

int main() {
    Zodiac* zodiacs = new Zodiac[NUMBER_OF_ZODIAC];
    init(zodiacs);
    int day, month;
    cout << "Nhap vao ngay sinh, thang sinh hop le: ";
    cin >> day >> month;
    if (month < 1 || month > 12) {
        cout << "INVALID MONTH" << endl;
    }
    else if (!validDay(month, day)) {
        cout << "INVALID DAY\n";
    } else {
        string result = findZodiac(zodiacs, month, day);
        cout << result << endl;
    }
    return 0;
}
