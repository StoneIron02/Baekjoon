#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long n;
  cin >> n;
  if (n == 0) {
    cout << 1;
    exit(0);
  }
  if (n < 0) {
    cout << 32;
    exit(0);
  }

  string bits = "";
  while (n > 0) {
    bits = to_string(n % 2) + bits;
    n /= 2;
  }
  cout << bits.size();
}