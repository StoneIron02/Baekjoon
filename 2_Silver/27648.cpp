#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;

  if (K < N + M - 1) {
    cout << "NO\n";
    exit(0);
  }

  cout << "YES\n";
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << (i + j + 1) << " ";
    }
    cout << "\n";
  }
}