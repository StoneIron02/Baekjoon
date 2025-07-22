#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str1, str2;
  cin >> str1 >> str2;

  int min_len = min(str1.length(), str2.length());
  string res;

  for (int i = 0; i < min_len; ++i) {
    if (i % 2 == 0)
      res += str1[i];
    else
      res += str2[i];
  }

  cout << res;
}