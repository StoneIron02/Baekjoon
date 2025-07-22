#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, X;
  cin >> N >> X;

  vector<int> T(N);
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
  }

  int cur = 0;
  while (true) {
    int idx = cur % N;
    int pitch = X + cur;

    if (pitch > T[idx]) {
      cout << idx + 1 << "\n";
      break;
    }

    ++cur;
  }
}