#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SuffixArray {
private:
  string s;
  int n;
  vector<int> sa;        // Suffix Array
  vector<int> lcp;       // Longest Common Prefix Array

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
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  auto suffix_array = SuffixArray(str);
  auto sa = suffix_array.getSA();
  auto lcp = suffix_array.getLCP();
  for (int i : sa) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  int cnt = 0;
  for (int i : lcp) {
    if (cnt == 0) {
      cout << "x ";
      cnt++;
    } else {
      cout << i << " ";
    }
  }
}