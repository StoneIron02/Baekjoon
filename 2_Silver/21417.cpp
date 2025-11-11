#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s;
  int k;
  cin >> s >> k;
  while (k--) {
    string left, right;
    for (int i = s.size() - 1; i >= 0; --i) {
      if ((s.size() - 1 - i) % 2 == 0) left += s[i];
      else right += s[i];
    }
    s = right + left;
  }
  cout << s;
}
