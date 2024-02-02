#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<int> skillLevel(4);
  for (int i = 0; i < 4; i++) {
    cin >> skillLevel[i];
  }
  string str = "0011";
  int minDiff = INT_MAX;
  do {
    int sum[2] {0, 0};
    for (int i = 0; i < 4; i++) {
      sum[str[i] - '0'] += skillLevel[i];
    }
    int diff = abs(sum[0] - sum[1]);
    minDiff = min(minDiff, diff);
  } while (next_permutation(str.begin(), str.end()));
  cout << minDiff;
}