#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int N, M, k, D;
    cin >> N >> M >> k >> D;
    int B = D / (k * N * M * (M-1) / 2 + N * (N-1) * M * M / 2);
    int res = (k * N * M * (M-1) / 2 + N * (N-1) * M * M / 2) * B;
    if (B < 1) {
      cout << -1 << "\n";
    } else {
      cout << res << "\n";
    }
  }
}