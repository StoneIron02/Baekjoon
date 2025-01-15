#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool arr[101];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    arr[num] = true;
  }
  vector<int> print;
  for (int i = 1; i <= n; i++) {
    if (!arr[i])
      print.push_back(i);
  }

  int latest = -1;
  int cost = 0;
  for (auto i : print) {
    if (latest == -1) {
      cost += 5 + 2 * 1;
    } else {
      cost += min(2 * (i - latest), 5 + 2 * 1);
    }
    latest = i;
  }
  cout << cost;
}