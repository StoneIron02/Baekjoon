#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(int m, int d) {
  if ((m == 1 && d <= 19)) return 11;
  if ((m == 1 && d >= 20) || (m == 2 && d <= 18)) return 0;
  if ((m == 2 && d >= 19) || (m == 3 && d <= 20)) return 1;
  if ((m == 3 && d >= 21) || (m == 4 && d <= 19)) return 2;
  if ((m == 4 && d >= 20) || (m == 5 && d <= 20)) return 3;
  if ((m == 5 && d >= 21) || (m == 6 && d <= 21)) return 4;
  if ((m == 6 && d >= 22) || (m == 7 && d <= 22)) return 5;
  if ((m == 7 && d >= 23) || (m == 8 && d <= 22)) return 6;
  if ((m == 8 && d >= 23) || (m == 9 && d <= 22)) return 7;
  if ((m == 9 && d >= 23) || (m == 10 && d <= 22)) return 8;
  if ((m == 10 && d >= 23) || (m == 11 && d <= 22)) return 9;
  if ((m == 11 && d >= 23) || (m == 12 && d <= 21)) return 10;
  return 11;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  bool flag[12] = {false};
  for (int i = 0; i < 7; ++i) {
    int m, d; 
    cin >> m >> d;
    flag[check(m, d)] = true;
  }

  int N; 
  cin >> N;
  vector<pair<int,int>> res;
  res.reserve(N);

  for (int i = 0; i < N; ++i) {
    int m, d; 
    cin >> m >> d;
    if (!flag[check(m, d)]) res.emplace_back(m, d);
  }

  sort(res.begin(), res.end(), [](const auto& a, const auto& b){
      if (a.first != b.first) return a.first < b.first;
      return a.second < b.second;
  });

  if (res.empty()) {
    cout << "ALL FAILED\n";
  } else {
    for (auto &i : res) cout << i.first << " " << i.second << "\n";
  }
}