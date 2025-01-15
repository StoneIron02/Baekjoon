#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 3; i++) {
    string startTime, endTime;
    cin >> startTime >> endTime;

    int startH = stoi(startTime.substr(0, 2));
    int startM = stoi(startTime.substr(3, 2));
    int startS = stoi(startTime.substr(6, 2));

    int endH = stoi(endTime.substr(0, 2));
    int endM = stoi(endTime.substr(3, 2));
    int endS = stoi(endTime.substr(6, 2));

    bool flag = false;
    if (startH > endH ||
        (startH == endH && startM > endM) ||
        (startH == endH && startM == endM && startS > endS)) {
      flag = true;
    }

    int cnt = 0;

    while (true) {
      int num = startH * 10000 + startM * 100 + startS;
      if (num % 3 == 0) {
        cnt++;
      }

      if (startH == endH && startM == endM && startS == endS) {
        break;
      }

      startS++;
      if (startS == 60) {
        startS = 0;
        startM++;
      }
      if (startM == 60) {
        startM = 0;
        startH++;
      }
      if (startH == 24) {
        startH = 0;
      }

      if (flag && startH == 0 && startM == 0 && startS == 0) {
        flag = false;
      }
    }

    cout << cnt << "\n";
  }

}