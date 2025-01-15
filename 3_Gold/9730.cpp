#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    long long cost = 0;
    vector<int> vec(N);
    for (int& i : vec) {
      cin >> i;
    }

    stack<int> stk;
    stk.push(vec[0]);
    int i = 1;
    while (i < vec.size()) {
      if (stk.top() > vec[i]) {
        stk.push(vec[i]);
        i++;
        continue;
      }
      if (stk.top() == vec[i]) {
        cost += vec[i];
        i++;
        continue;
      }

      int mid = stk.top();
      stk.pop();
      if (stk.empty() || stk.top() > vec[i]) {
        cost += vec[i];
        stk.push(vec[i]);
        i++;
      } else {
        cost += stk.top();
      }
    }

    while (stk.size() > 1) {
      int out = stk.top();
      stk.pop();
      cost += stk.top();
    }

    cout << "Case #" << t << ": " << cost << "\n";
  }
}