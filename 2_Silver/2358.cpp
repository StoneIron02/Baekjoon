#include <iostream>
#include <ranges>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  unordered_map<int, int> x_pos;
  unordered_map<int, int> y_pos;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ++x_pos[x];
    ++y_pos[y];
  }

  int cnt = 0;
  for (auto& val : x_pos | views::values) {
    if (val >= 2) ++cnt;
  }
  for (auto& val : y_pos | views::values) {
    if (val >= 2) ++cnt;
  }
  cout << cnt;
}