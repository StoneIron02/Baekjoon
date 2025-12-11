#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long N;
  cin >> N;
  if (N == 0) {
    cout << 0;
    return 0;
  }

  string r;
  while (N != 0) {
    long long rem = N % -2;
    N /= -2;
    if (rem < 0) {
      rem += 2;
      N += 1;
    }
    r.push_back(static_cast<char>('0' + rem));
  }

  ranges::reverse(r);
  cout << r;
}
