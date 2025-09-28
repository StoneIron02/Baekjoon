#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  unordered_map<string, int> cnt;
  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    if (str.size() < M) continue;
    ++cnt[str];
  }

  vector<string> words;
  for (auto& [word, tmp] : cnt) {
    words.push_back(word);
  }

  sort(words.begin(), words.end(), [&](const string &a, const string &b) {
      if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
      if (a.size() != b.size()) return a.size() > b.size();
      return a < b;
  });

  for (auto& word : words) {
    cout << word << "\n";
  }
}