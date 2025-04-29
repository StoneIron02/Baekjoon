#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<string> words_origin(n);
  vector<pair<string, int>> words(n);
  for (int i = 0; i < words.size(); i++) {
    string str;
    cin >> str;
    words_origin[i] = str;
    words[i] = {str, i};
  }
  sort(words.begin(), words.end());

  int max_lcp_len = 0;
  int max_lcp = 0;
  for (int i = 1; i < words.size(); i++) {
    int k = 0;
    while (k < words[i - 1].first.size() && k < words[i].first.size() && words[i - 1].first[k] == words[i].first[k])
      k++;
    if (max_lcp_len < k) {
      max_lcp_len = k;
      max_lcp = i - 1;
    }
    if (max_lcp_len == k) {
      max_lcp = words[max_lcp].second < words[i].second ? max_lcp : i - 1;
    }
  }
  string lcp_str;
  for (int i = 0; i < max_lcp_len; i++) {
    lcp_str += words[max_lcp].first[i];
  }

  int printCnt = 0;
  string word1;
  for (int i = 0; i < words_origin.size(); i++) {
    bool flag = true;
    for (int k = 0; k < max_lcp_len; k++) {
      if (lcp_str[k] != words_origin[i][k]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      if (printCnt == 0) {
        cout << words_origin[i] << "\n";
        word1 = words_origin[i];
        printCnt++;
      } else {
        if (word1 != words_origin[i]) {
          cout << words_origin[i] << "\n";
          exit(0);
        }
      }
    }
  }


}
