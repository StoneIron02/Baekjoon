#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  while (getline(cin, str)) {
    long long R1 = 0, R2 = 0;
    char R3 = 0;
    bool err = false;

    for (char c : str) {
      if (err) {
        if (c == '=') {
          cout << "E\n";
        }
        continue;
      }

      if (c >= '0' && c <= '9') {
        R2 = R2 * 10 + (c - '0');
        if (R2 > 9999) err = true;
      } else if (c == '+' || c == '-' || c == '*' || c == '=') {
        long long res;
        if (R3 == 0) res = R2;
        else if (R3 == '+') res = R1 + R2;
        else if (R3 == '-') res = R1 - R2;
        else res = R1 * R2;

        if (res < 0 || res > 9999) {
          err = true;
        } else {
          R1 = res;
          R2 = 0;
          if (c != '=') R3 = c;
        }

        if (c == '=') {
          if (err) cout << "E\n";
          else cout << R1 << "\n";
        }
      }
    }
  }
}