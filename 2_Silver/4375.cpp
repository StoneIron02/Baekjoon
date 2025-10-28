#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  while (cin >> n) {
    queue<pair<string, int>> que;
    vector<bool> visit(n, false);

    que.emplace("1", 1 % n);
    visit[1 % n] = true;

    while (!que.empty()) {
      auto [str, cur] = que.front();
      que.pop();

      if (cur == 0) {
        cout << str.length() << "\n";
        break;
      }

      int next = (cur * 10 + 1) % n;
      if (!visit[next]) {
        visit[next] = true;
        que.emplace(str + "1", next);
      }
    }
  }

}
