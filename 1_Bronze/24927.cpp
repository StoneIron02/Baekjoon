#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  int need = K;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;

    int c = 0;
    while (x % 2 == 0) {
      x /= 2;
      ++c;
    }
    need -= c;
    if (need <= 0) {
      cout << 1;
      return 0;
    }
  }

  cout << 0;
}
