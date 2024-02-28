#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int a, b, x;
    cin >> a >> b >> x;
    int w = a * (x - 1) + b;
    cout << w << "\n";
  }
}