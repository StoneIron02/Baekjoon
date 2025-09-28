#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  deque<char> deq;
  stack<pair<int, char>> stk;
  for (int i = 0; i < N; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      char c;
      cin >> c;
      deq.push_back(c);
      stk.push({1, c});
    } else if (type == 2) {
      char c;
      cin >> c;
      deq.push_front(c);
      stk.push({2, c});
    } else if (type == 3) {
      if (stk.empty()) continue;
      auto& [type, c] = stk.top(); stk.pop();
      if (type == 1) {
        if (!deq.empty() && deq.back() == c) deq.pop_back();
      } else {
        if (!deq.empty() && deq.front() == c) deq.pop_front();
      }
    }
  }

  if (deq.empty()) {
    cout << 0 << "\n";
  } else {
    for (char c : deq) cout << c;
    cout << "\n";
  }
}