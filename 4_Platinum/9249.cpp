#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

class SuffixArray {
private:
  string s;
  int n;
  vector<int> sa;
  vector<int> lcp;

public:
  explicit SuffixArray(const string& str) : s(str), n(str.size()) {
    buildSuffixArray();
    buildLCPArray();
  }

  [[nodiscard]] const vector<int>& getSA() const { return sa; }
  [[nodiscard]] const vector<int>& getLCP() const { return lcp; }

  void buildSuffixArray() {
    vector<int> rank(n), tmp(n);
    sa.resize(n);
    for (int i = 0; i < n; ++i) {
      sa[i] = i;
      rank[i] = s[i];
    }

    for (int k = 1; k < n; k <<= 1) {
      auto cmp = [&](int i, int j) {
        if (rank[i] != rank[j]) return rank[i] < rank[j];
        int ri = (i + k < n) ? rank[i + k] : -1;
        int rj = (j + k < n) ? rank[j + k] : -1;
        return ri < rj;
      };
      sort(sa.begin(), sa.end(), cmp);

      tmp[sa[0]] = 0;
      for (int i = 1; i < n; ++i) {
        tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
      }
      rank = tmp;
    }
  }

  void buildLCPArray() {
    lcp.resize(n);
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;

    int h = 0;
    for (int i = 0; i < n; ++i) {
      if (rank[i] == 0) continue;
      int j = sa[rank[i] - 1];
      while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
      lcp[rank[i]] = h;
      if (h > 0) --h;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string A, B;
  cin >> A >> B;
  string S = A + '#' + B + '$';

  SuffixArray s(S);
  auto& sa = s.getSA();
  auto& lcp = s.getLCP();

  int maxLen = 0;
  int maxLcpIdx;
  for (int i = 1; i < S.size(); ++i) {
    if ((sa[i - 1] < A.size()) == (sa[i] < A.size())) continue;
    if (maxLen < lcp[i]) {
      maxLen = lcp[i];
      maxLcpIdx = i;
    }
  }

  int start = sa[maxLcpIdx];
  cout << maxLen << "\n";
  cout << S.substr(start, maxLen);
}