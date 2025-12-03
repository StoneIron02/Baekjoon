#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h, M;
  cin >> h >> M;

  for (int t = 1; t <= M; ++t) {
    long long A = -6LL * t * t * t * t + 1LL * h * t * t * t + 2LL * t * t + t;
    if (A <= 0) {
      cout << "The balloon first touches ground at hour: " << t << "\n";
      return 0;
    }
  }

  cout << "The balloon does not touch ground in the given time.\n";
}
