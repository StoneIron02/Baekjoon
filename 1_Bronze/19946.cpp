#include <iostream>
#include <climits>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  unsigned long long origin = ULLONG_MAX;
  unsigned long long N;
  cin >> N;
  int cur = 64;

  while (origin != N) {
    origin /= 2;
    N /= 2;
    cur--;
  }

  cout << cur;
}