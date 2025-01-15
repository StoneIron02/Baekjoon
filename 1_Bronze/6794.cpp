#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i <= n / 2; i++) {
    int j = n - i;
    if (i <= 5 && j <= 5) {
      cnt++;
    }
  }
  cout << cnt;
}