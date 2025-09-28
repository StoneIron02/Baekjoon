#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  vector<long long> left, right;
  for (int i = 0; i < N; i++) {
    long long x;
    cin >> x;
    if (x < 0) left.push_back(-x);
    else right.push_back(x);
  }

  sort(left.rbegin(), left.rend());
  sort(right.rbegin(), right.rend());

  long long total = 0;
  for (int i = 0; i < left.size(); i += K) {
    total += 2 * left[i];
  }
  for (int i = 0; i < right.size(); i += K) {
    total += 2 * right[i];
  }
  cout << total;
}