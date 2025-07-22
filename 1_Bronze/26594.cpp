#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int max_cnt = 1;
  int cur_cnt = 1;

  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      cur_cnt++;
      if (cur_cnt > max_cnt) {
        max_cnt = cur_cnt;
      }
    } else {
      cur_cnt = 1;
    }
  }

  cout << max_cnt;
}