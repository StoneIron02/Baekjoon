#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int N, A, D;
    cin >> N >> A >> D;
    cout << N * (2 * A + (N - 1) * D) / 2 << "\n";
  }
}