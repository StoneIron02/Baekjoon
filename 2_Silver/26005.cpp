#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }

  if (n * n % 2 == 0) {
    cout << n * n / 2;
  } else {
    cout << n * n / 2 + 1;
  }
}