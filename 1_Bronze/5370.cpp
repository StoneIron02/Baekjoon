#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int num;
  while (cin >> num) {
    string b;
    if (num == 0) {
      b = "0";
    } else {
      while (num > 0) {
        b += '0' + (num % 2);
        num /= 2;
      }
      reverse(b.begin(), b.end());
    }

    int cnt[2] = {0, 0};
    for (char c : b) {
      cnt[c - '0']++;
    }
    if (cnt[0] > cnt[1]) {
      cout << "left\n";
    } else if (cnt[0] < cnt[1]) {
      cout << "right\n";
    } else {
      cout << "straight\n";
    }
  }
}