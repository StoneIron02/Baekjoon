#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  long long fact = 1;
  for (int i = 2; i <= n; i++) {
    fact = (fact * i) % 1'000'000'007;
  }
  cout << fact;
}