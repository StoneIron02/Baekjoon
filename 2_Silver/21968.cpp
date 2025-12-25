#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    long long N;
    cin >> N;

    long long res = 0;
    long long power = 1;

    while (N > 0) {
      if (N & 1) res += power;
      power *= 3;
      N >>= 1;
    }

    string str;
    if (res == 0) str = "0";
    else {
      while (res > 0) {
        str.push_back('0' + res % 10);
        res /= 10;
      }
      reverse(str.begin(), str.end());
    }

    cout << str << "\n";
  }
}
