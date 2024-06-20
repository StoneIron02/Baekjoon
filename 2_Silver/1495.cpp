#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int diff[51];
unordered_set<int> tables[2];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, S, M;
  cin >> N >> S >> M;
  for (int i = 1; i <= N; i++) {
    cin >> diff[i];
  }
  tables[0].insert(S);
  for (int i = 1; i <= N; i++) {
    for (int val : tables[0]) {
      if (0 <= val - diff[i]) {
        tables[1].insert(val - diff[i]);
      }
      if (val + diff[i] <= M) {
        tables[1].insert(val + diff[i]);
      }
    }
    swap(tables[0], tables[1]);
    tables[1].clear();
  }
  if (tables[0].empty()) {
    cout << -1;
  } else {
    int maxVal = -1;
    for (int val : tables[0]) {
      maxVal = max(maxVal, val);
    }
    cout << maxVal;
  }
}