#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<long long> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  long long maxLemons = 0;
  for (int i = 0; i < N; ++i) {
    long long remaining = a[i] - (N + 1 - (i + 1));
    if (remaining > maxLemons) {
      maxLemons = remaining;
    }
  }

  cout << max(0LL, maxLemons);
}