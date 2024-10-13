#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  if (n > k + 60) {
    cout << 1500 * (k + 60) + 3000 * (n - k - 60);
  } else {
    cout << 1500 * n;
  }
}