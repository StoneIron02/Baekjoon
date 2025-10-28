#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> e(M + 1);
  vector<int> cnt(N + 1);
  for (int i = 1; i <= M; ++i) {
    cin >> e[i];
    if (e[i] != 0) ++cnt[e[i]];
  }

  for (int i = 0; i < Q; ++i) {
    string op;
    cin >> op;
    if (op == "assign") {
      int x, y;
      cin >> x >> y;
      --cnt[e[x]];
      ++cnt[e[y]];
      e[x] = e[y];
    }
    else if (op == "swap") {
      int x, y;
      cin >> x >> y;
      swap(e[x], e[y]);
    }
    else if (op == "reset") {
      int x;
      cin >> x;
      --cnt[e[x]];
      e[x] = 0;
    }
  }

  vector<int> res;
  for (int i = 1; i <= N; ++i) {
    if (cnt[i] > 0) res.push_back(i);
  }
  cout << res.size() << "\n";
  for (int& x : res) cout << x << "\n";
}