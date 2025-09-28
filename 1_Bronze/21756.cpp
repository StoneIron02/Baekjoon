#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int ans = 1;
  while ((ans << 1) <= N) ans <<= 1;
  cout << ans;
}