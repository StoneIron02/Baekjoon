#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  int max_n = min(a, b);
  for (int i = 1; i <= max(a, b); ++i) {
    if (a % i == 0 && b % i == 0) {
      cout << i << " " << a / i << " " << b / i << '\n';
    }
  }
}
