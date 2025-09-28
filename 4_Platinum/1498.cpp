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

  string S;
  cin >> S;

  vector<int> failure = failure_function(S);
  for (int i = 0; i < S.size(); ++i) {
    int L = i + 1;
    int period = L - failure[i];
    if (period > 0 && L % period == 0) {
      int k = L / period;
      if (k > 1) {
        cout << L << ' ' << k << '\n';
      }
    }
  }
}