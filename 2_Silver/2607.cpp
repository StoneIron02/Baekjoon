#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  string origin;
  cin >> n >> origin;
  vector<int> origin_cnt(26, 0);
  for (char c : origin)
    ++origin_cnt[c - 'A'];

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    string w;
    cin >> w;

    vector<int> cnt(26, 0);
    for (char c : w) ++cnt[c - 'A'];

    int diff = 0;
    for (int j = 0; j < 26; ++j) {
      diff += abs(origin_cnt[j] - cnt[j]);
    }

    if (diff == 0) ++ans;
    else if (diff == 1) ++ans;
    else if (diff == 2 && origin.size() == w.size()) ++ans;
  }

  cout << ans;
}
