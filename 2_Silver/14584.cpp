#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool check(const string & res, const vector<string> & words) {
  for (auto& word : words) {
    auto it = search(res.begin(), res.end(), boyer_moore_horspool_searcher(word.begin(), word.end()));
    if (it != res.end()) {
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string encrypted;
  cin >> encrypted;
  int N;
  cin >> N;
  vector<string> words(N);
  for (auto& i : words) {
    cin >> i;
  }

  for (int i = 0; i < 26; i++) {
    string res;
    for (char c : encrypted) {
      res += static_cast<char>((c - 'a' + i) % 26 + 'a');
    }
    if (check(res, words)) {
      cout << res;
      break;
    }
  }
}
