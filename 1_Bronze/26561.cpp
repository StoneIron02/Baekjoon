#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    long long p, t;
    cin >> p >> t;
    p -= t / 7;
    p += t / 4;
    cout << p << "\n";
  }
}