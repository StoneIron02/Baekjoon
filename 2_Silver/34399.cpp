#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  unordered_set<string> keywords;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (auto &c : s) c = tolower(c);
    keywords.insert(s);
  }

  int M;
  cin >> M;
  while (M--) {
    string word;
    cin >> word;
    int L = word.size();
    vector<long long> dp(L + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= L; ++i) {
      for (int len = 1; len <= 5 && i - len >= 0; ++len) {
        string sub = word.substr(i - len, len);
        if (keywords.count(sub)) dp[i] += dp[i - len];
      }
    }
    cout << dp[L] << '\n';
  }
}