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

  int T = 0;
  while (++T) {
    int N;
    cin >> N;
    if (N == 0) break;
    string S;
    cin >> S;

    vector<int> failure = failure_function(S);
    cout << "Test case #" << T << "\n";
    for (int i = 2; i <= N; ++i) {
      int period = i - failure[i - 1];
      if (failure[i - 1] > 0 && i % period == 0) {
        int K = i / period;
        if (K > 1) cout << i << " " << K << "\n";
      }
    }
    cout << "\n";
  }
}