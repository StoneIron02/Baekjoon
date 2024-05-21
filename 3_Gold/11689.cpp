#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long n;
  cin >> n;
  long long phi = n;
  for (long long p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      phi -= phi / p;
      while (n % p == 0) {
        n /= p;
      }
    }
  }
  if (n > 1) {
    phi -= phi / n;
  }
  cout << phi;
}