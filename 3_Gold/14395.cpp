#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  long long s, t;
  cin >> s >> t;

  if (s == t) {
    cout << "0";
    return 0;
  }

  queue<pair<long long, string>> que;
  unordered_set<long long> visited;
  vector<string> sol;
  que.emplace(s, "");
  visited.insert(s);

  while (!que.empty()) {
    auto [cur, op] = que.front();
    que.pop();

    if (cur == t) {
      if (!sol.empty() && sol[0].size() > op.size()) {
        sol.clear();
      }
      sol.push_back(op);
      continue;
    }

    // *
    if (cur <= 1'000'000'000 && visited.find(cur * cur) == visited.end()) {
      visited.insert(cur * cur);
      que.emplace(cur * cur, op + "*");
    }

    // +
    if (cur <= 1'000'000'000 && visited.find(cur + cur) == visited.end()) {
      visited.insert(cur + cur);
      que.emplace(cur + cur, op + "+");
    }

    // -
    if (visited.find(0) == visited.end()) {
      visited.insert(0);
      que.emplace(0, op + "-");
    }

    // /
    if (cur != 0 && visited.find(1) == visited.end()) {
      visited.insert(1);
      que.emplace(1, op + "/");
    }
  }

  sort(sol.begin(), sol.end());

  if (sol.empty()) {
    cout << -1;
    return 0;
  }
  cout << sol[0];
}
