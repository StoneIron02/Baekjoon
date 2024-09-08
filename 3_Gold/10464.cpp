#include <iostream>

using namespace std;

long long getXor(long long n) {
  switch (n % 4) {
    case 0:
      return n;
    case 1:
      return 1;
    case 2:
      return n + 1;
    default:
      return 0;
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    long long s, f;
    cin >> s >> f;
    cout << (getXor(f) ^ getXor(s - 1)) << "\n";
  }
}