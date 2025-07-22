#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<vector<string>> text;
  string str;

  while (getline(cin, str)) {
    vector<string> words;
    stringstream ss(str);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    text.push_back(words);
  }

  size_t max_col = 0;
  for (auto& line : text) {
    max_col = max(max_col, line.size());
  }

  vector<size_t> max_cnt(max_col, 0);
  for (auto& line : text) {
    for (size_t i = 0; i < line.size(); ++i) {
      max_cnt[i] = max(max_cnt[i], line[i].size());
    }
  }

  for (auto& line : text) {
    for (size_t i = 0; i < line.size(); ++i) {
      cout << line[i];
      if (i != line.size() - 1) {
        cout << string(max_cnt[i] - line[i].size() + 1, ' ');
      }
    }
    cout << '\n';
  }

}