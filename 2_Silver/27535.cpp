#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string to_base(long long x, int b) {
  if (x == 0) return "0";
  string s;
  while (x > 0) {
    s.push_back(static_cast<char>('0' + x % b));
    x /= b;
  }
  ranges::reverse(s);
  return s;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int H, T, C, K, G;
  cin >> H >> T >> C >> K >> G;
  int M;
  cin >> M;

  int prev_total = H + T + C + K + G;

  for (int i = 0; i < M; i++) {
    int h, t, c, k, g;
    cin >> h >> t >> c >> k >> g;

    H -= h;
    T -= t;
    C -= c;
    K -= k;
    G -= g;

    int cur_total = H + T + C + K + G;

    int last_digit = prev_total % 10;
    int base = (last_digit == 0 || last_digit == 1) ? 10 : last_digit;

    string num = to_base(cur_total, base);

    cout << num << "7H\n";

    if (cur_total == 0) {
      cout << "NULL\n";
    } else {
      vector<pair<int, char>> v;
      if (H > 0) v.emplace_back(H,'H');
      if (T > 0) v.emplace_back(T,'T');
      if (C > 0) v.emplace_back(C,'C');
      if (K > 0) v.emplace_back(K,'K');
      if (G > 0) v.emplace_back(G,'G');

      ranges::sort(v, [&] (auto& a, auto& b) {
          if (a.first != b.first) return a.first > b.first;
          return a.second < b.second;
      });

      for (auto& p : v) cout << p.second;
      cout << "\n";
    }

    prev_total = cur_total;
  }
}