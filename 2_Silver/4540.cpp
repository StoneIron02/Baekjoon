#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int m, n;
    cin >> m >> n;
    vector<string> item(m);
    for (int i = 0; i < m; ++i) cin >> item[i];
    
    vector<pair<int, int>> query(n);
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      query[i] = {a - 1, b - 1};
    }
    
    vector<string> res(m, "");
    vector<bool> flag(m);
    for (auto &q : query) {
      res[q.second] = item[q.first];
      flag[q.second] = true;
    }

    int j = 0;
    for (int i = 0; i < m; ++i) {
      if (!flag[i]) {
        while (ranges::find_if(query, [&](auto &p) { return p.first == j; }) != query.end()) ++j;
        res[i] = item[j++];
      }
    }
    for (int i = 0; i < m; ++i) {
      cout << res[i] << " ";
    }
    cout << "\n";
  }
}
