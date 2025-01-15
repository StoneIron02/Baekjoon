#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> cnt[100];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    cnt[j] = {0, j + 1};
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool result;
      cin >> result;
      if (result)
        cnt[j].first++;
    }
  }
  sort(cnt, cnt + m, [](pair<int, int>& lv, pair<int, int>& rv) -> bool {
    if (lv.first == rv.first)
      return lv.second < rv.second;
    return lv.first > rv.first;
  });
  for (int j = 0; j < m; j++) {
    cout << cnt[j].second << " ";
  }
}