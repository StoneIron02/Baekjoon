#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  for (int t = 1; t <= T; ++t) {
    int H, M;
    cin >> H >> M;

    M -= 45;
    if (M < 0) {
      M += 60;
      H--;
      if (H < 0) H = 23;
    }

    cout << "Case #" << t << ": " << H << " " << M << "\n";
  }
}
