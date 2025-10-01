#include <iostream>
#include <vector>
using namespace std;

/**
 * Manacher's Algorithm
 * @param s 문자열
 * @return 각 중심에서의 팰린드롬 반지름
 */
vector<int> manacher(const vector<int>& s) {
  int n = s.size();
  if (n == 0) return {};

  vector<int> t = {-1};
  for (auto& c : s) {
    t.push_back(-2);
    t.push_back(c);
  }
  t.push_back(-2);
  t.push_back(-3);

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
  
  int N;
  cin >> N;
  vector<int> arr(N);
  for (auto& i : arr) {
    cin >> i;
  }
  auto res = manacher(arr);
  int M;
  cin >> M;
  while (M--) {
    int S, E;
    cin >> S >> E;

    int a = 2 * (S - 1);
    int b = 2 * E - 2;
    cout << (res[(a + b) / 2] >= E - S + 1) << "\n";
  }
}
