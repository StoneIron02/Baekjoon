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
  while (cin >> s && s != ".") {
    vector<int> failure = failure_function(s);
    int l = s.size() - failure[s.size() - 1];
    if (s.size() % l == 0)
      cout << s.size() / l << '\n';
    else
      cout << 1 << '\n';
  }
}