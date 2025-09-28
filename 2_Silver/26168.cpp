#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<long long> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];

  sort(A.begin(), A.end());

  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      long long k;
      cin >> k;
      auto it = ranges::lower_bound(A, k);
      cout << (A.end() - it) << "\n";
    }
    else if (type == 2) {
      long long k;
      cin >> k;
      auto it = ranges::upper_bound(A, k);
      cout << (A.end() - it) << "\n";
    }
    else if (type == 3) {
      long long i, j;
      cin >> i >> j;
      auto left = ranges::lower_bound(A, i);
      auto right = ranges::upper_bound(A, j);
      cout << (right - left) << "\n";
    }
  }
}