#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;
  vector<pair<double, int>> arr;
  for (int g = 0; g < M; ++g) {
    for (int j = 0; j < N; ++j) {
      int i;
      double s;
      cin >> i >> s;
      arr.emplace_back(s, i - 1);
    }
  }

  sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
    return a.first > b.first;
  });

  vector<bool> flag(N, false);
  int cnt = 0;
  double sum = 0;
  for (auto& c : arr) {
    if (cnt == K) break;
    if (!flag[c.second]) {
      flag[c.second] = true;
      sum += c.first;
      ++cnt;
    }
  }

  cout << fixed << setprecision(1) << sum << "\n";
}
