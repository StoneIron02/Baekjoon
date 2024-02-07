#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "#\n\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      cout << "#";
      if (i == 0 || i == n - 1) {
        for (int j = 0; j < n - 2; j++) {
          cout << "#";
        }
      } else {
        for (int j = 0; j < n - 2; j++) {
          cout << "J";
        }
      }
      cout << "#";
      cout << "\n";
    }
    cout << "\n";
  }
}