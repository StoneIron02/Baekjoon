#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int m;
  cin >> m;
  while (m--) {
    int n, c;
    cin >> n >> c;
    vector<int> arr(c);
    for (int i = 0; i < c; ++i) {
      cin >> arr[i];
    }

    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> pq;

    for (int i = 1; i <= n; ++i) {
      pq.push({0, i});
    }

    vector<int> res(c);
    for (int i = 0; i < c; ++i) {
      auto [finish, id] = pq.top();
      pq.pop();
      res[i] = id;
      pq.push({finish + arr[i], id});
    }

    for (int i = 0; i < c; ++i) {
      if (i) cout << " ";
      cout << res[i];
    }
    cout << "\n";
  }
}
