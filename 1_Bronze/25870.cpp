#include <iostream>

using namespace std;

int cnt[26];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  for (char c : str) {
    cnt[c - 'a']++;
  }

  bool flag1 = true, flag2 = true;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2 == 1) flag1 = false;
    if (cnt[i] != 0 && cnt[i] % 2 == 0) flag2 = false;
  }
  if (flag1) cout << 0;
  else if (flag2) cout << 1;
  else cout << 2;
}