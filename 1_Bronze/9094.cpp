#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;

    int count = 0;
    for (int a = 1; a < n; a++) {
      for (int b = a + 1; b < n; b++) {
        if (((a * a + b * b + m) % (a * b)) == 0) {
          count++;
        }
      }
    }

    cout << count << "\n";
  }

}