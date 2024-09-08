#include <iostream>

using namespace std;

long long MOD = 1000000007;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  long long cnt = 0;
  for (long long i = 0, w = 1; i < str.size(); i++, w = (w * 2) % MOD) {
    if (str[i] == 'O') {
      cnt = (cnt + w) % MOD;
    }
  }
  cout << cnt;
}