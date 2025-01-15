#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i % 7 == 0 && i % 11 == 0) {
      cout << "Wiwat!\n";
    } else if (i % 7 == 0) {
      cout << "Hurra!\n";
    } else if (i % 11 == 0) {
      cout << "Super!\n";
    } else {
      cout << i << "\n";
    }
  }
}