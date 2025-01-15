#include <iostream>

using namespace std;

int cnt[10];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long a, b, c;
  cin >> a >> b >> c;

  long long mul = a * b * c;
  string str = to_string(mul);
  for (char ch : str) {
    cnt[ch - '0']++;
  }

  for (int i = 0; i < 10; i++) {
    cout << cnt[i] << "\n";
  }
}