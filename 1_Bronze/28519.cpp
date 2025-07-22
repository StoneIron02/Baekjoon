#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long n, m;
  cin >> n >> m;

  long long res = 2 * min(n, m);
  if (n != m) res += 1;

  cout << res;
}