#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Manacher's Algorithm
 * @param s 문자열
 * @return 각 중심에서의 팰린드롬 반지름
 */
vector<int> manacher(const string& s) {
  int n = s.size();
  if (n == 0) return {};

  string t = "^";
  for (char c : s) {
    t += "#" + string(1, c);
  }
  t += "#$";

  int m = t.size();
  vector<int> p(m, 0);
  int center = 0, right = 0;

  for (int i = 1; i < m - 1; ++i) {
    int mirror = 2 * center - i;
    if (i < right) {
      p[i] = min(right - i, p[mirror]);
    }

    while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
      p[i]++;
    }

    if (i + p[i] > right) {
      center = i;
      right = i + p[i];
    }
  }

  vector<int> result;
  for (int i = 2; i < m - 2; ++i) {
      result.push_back(p[i]);
  }

  return result;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  auto len = manacher(str);
  auto res = *max_element(len.begin(), len.end());
  cout << res;
}
