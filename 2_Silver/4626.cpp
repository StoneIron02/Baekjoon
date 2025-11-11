#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N, D, B, E;
    cin >> N >> D >> B >> E;

    cout << "Problem set " << t << ": " << N << " / " << D << ", ";

    N %= D;
    for (int i = 0; i < B; ++i) {
      N *= 7;
      N %= D;
    }

    cout << "base 7 digits " << B << " through " << E << ": ";

    string res;
    for (int i = B; i <= E; ++i) {
      N *= 7;
      int digit = N / D;
      res += static_cast<char>('0' + digit);
      N %= D;
    }

    cout << res << "\n";
  }
}
