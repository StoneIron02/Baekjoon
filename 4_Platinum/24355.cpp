#include <algorithm>
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

  string s;
  cin >> s;
  string rev_s = s;
  ranges::reverse(rev_s);

  string tot = s + "$" + rev_s;
  vector<int> failure = failure_function(tot);
  int res = s.length() + (s.length() - failure.back());
  cout << res;
}