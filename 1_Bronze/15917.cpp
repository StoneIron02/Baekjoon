#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    int a;
    cin >> a;
    while (a % 2 == 0) {
      a /= 2;
    }
    cout << (a == 1) << "\n";
  }
}