#include <iostream>

using namespace std;

bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
    return false;
}

int convertDayStamp(int y, int m, int d) {
    int sum = 0;

    for(int i = 1; i < y; i++){ // 1년 1월 1일 ~ y-1년 12월 31일
        sum += 365;
        if (isLeap(i))
            sum += 1;
    }

    for(int i = 1; i < m; i++){ // y년 1월 1일 ~ y년 m-1월 마지막 날
        if (i == 2) {
            sum += 28;
            if (isLeap(y))
                sum += 1;
        } else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            sum += 31;
        } else {
            sum += 30;
        }
    }

    sum += d; // y년 m월 1일 ~ y년 m월 d일
    return sum;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

    if ((y2 - y1 > 1000) || (y2 - y1 == 1000 && m2 > m1)
        || (y2 - y1 == 1000 && m2 == m1 && d2 >= d1)) {
        cout << "gg";
        return 0;
    }

    int dayStamp1 = convertDayStamp(y1, m1, d1);
    int dayStamp2 = convertDayStamp(y2, m2, d2);
    int diff = dayStamp2 - dayStamp1;
    cout << "D-" << diff;
}