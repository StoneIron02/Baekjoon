#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i <= 10) {
      for (int j = 1; j <= i * i; j++) {
        cout << '*';
      }
    } else {
      for (int j = 1; j <= 100; j++) {
        cout << '*';
      }
      cout << "...";
    }

    cout << "\n";
  }
}