#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int R, B;
  cin >> R >> B;

  int total = R + B;

  for (int W = 1; W * W <= total; W++) {
    if (total % W == 0) {
      int L = total / W;

      if ((L * 2 + (W - 2) * 2) == R) {
        cout << L << " " << W << "\n";
        return 0;
      }
    }
  }
}