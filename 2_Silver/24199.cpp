#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> run(const int N, const vector<int>& depth) {
  vector<int> start;
  for (int i = 1; i <= N; ++i) {
    start.push_back(i);
  }
  vector<int> end(N);

  for (int d : depth) {
    stack<int> stk;
    int i = 0, j = 0;
    for (; i < d; i++) {
      stk.push(start[i]);
    }
    for (; i < N; ++i) {
      end[j++] = start[i];
    }
    while (!stk.empty()) {
      end[j++] = stk.top();
      stk.pop();
    }
    start = end;
  }

  return start;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  vector<int> goal(N);
  for (int i = N - 1; i >= 0; --i) {
    cin >> goal[i];
  }

  for (int d1 = 1; d1 < N; d1++) {
    for (int d2 = 1; d2 < N; d2++) {
      for (int d3 = 1; d3 < N; d3++) {
        vector<int> res = run(N, {d1, d2, d3});
        if (res == goal) {
          cout << d1 << " " << d2 << " " << d3 << "\n";
          return 0;
        }
      }
    }
  }
}