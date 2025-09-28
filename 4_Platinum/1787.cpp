#include <iostream>
#include <vector>
using namespace std;

vector<int> failure_function(const string& s) {
  int n = s.size();
  vector<int> failure(n);
  for (int i = 1, j = 0; i < n; ++i) {
    while (j > 0 && s[i] != s[j])
      j = failure[j - 1];
    if (s[i] == s[j])
      failure[i] = ++j;
  }
  return failure;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> failure = failure_function(s);
  vector<int> minBorder(n + 1);
  for (int i = 1; i <= n; ++i) {
    int b = failure[i - 1];
    if (b != 0) minBorder[i] = (minBorder[b] > 0 ? minBorder[b] : b);
  }

  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    int l = minBorder[i];
    if (l > 0 && l * 2 <= i) res += 1LL * (i - l);
  }
  cout << res;
}