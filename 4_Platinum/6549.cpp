#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  while (true) {
    cin >> n;
    if (n == 0) break;
    vector<long long> heights(n);
    for (auto& i : heights) {
      cin >> i;
    }
    heights.push_back(0);

    stack<long long> stk;
    long long res = 0;
    for (int i = 0; i < heights.size(); i++) {
      while (!stk.empty() && heights[stk.top()] > heights[i]) {
        auto height = heights[stk.top()];
        stk.pop();
        auto width = stk.empty() ? i : i - stk.top() - 1;
        res = max(res, width * height);
      }
      stk.push(i);
    }

    cout << res << "\n";
  }

}