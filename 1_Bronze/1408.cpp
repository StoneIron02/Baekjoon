#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int time(const string& timeStr) {
    int hour, minute, second;
    stringstream ss(timeStr);
    char delimiter;
    ss >> hour >> delimiter >> minute >> delimiter >> second;
    int result = 0;
    result += (hour * 60 * 60);
    result += (minute * 60);
    result += second;
    return result;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string target, cur;
    cin >> cur >> target;
    int targetTime, curTime;
    targetTime = time(target);
    curTime = time(cur);

    int delta = targetTime - curTime;
    if (delta < 0) {
        delta += (24 * 60 * 60);
    }

    int hour = delta / (60 * 60);
    int minute = delta % (60 * 60) / 60;
    int second = delta % (60 * 60) % 60;
    cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second;
}