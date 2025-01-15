#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, T;
  cin >> N >> T;

  int circle = 4 * N - 2;
  T = (T - 1) % circle + 1;

  int res;
  if (T <= 2 * N) {
    res = T;
  } else {
    res = 4 * N - T;
  }
  cout << res << endl;
}