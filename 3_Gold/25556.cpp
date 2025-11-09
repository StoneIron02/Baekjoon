#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  
  stack<int> stk[4];
  for (int i = 0; i < 4; ++i) {
    stk[i].push(0);
  }

  for (int& x : arr) {
    int best_idx = -1;
    int best_diff = INT_MAX;
    for (int i = 0; i < 4; ++i) {
      if (stk[i].top() < x && x - stk[i].top() < best_diff) {
        best_diff = x - stk[i].top();
        best_idx = i;
      }
    }

    if (best_idx == -1) {
      cout << "NO";
      return 0;
    }
    stk[best_idx].push(x);
  }
  cout << "YES";
}