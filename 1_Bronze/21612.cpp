#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int B;
  cin >> B;
  int P = 5 * B - 400;

  cout << P << "\n";
  if (P < 100) {
    cout << 1;
  } else if (P > 100) {
    cout << -1;
  } else {
    cout << 0;
  }
}