#include <iostream>
using namespace std;

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int cnt(const string& s) {
  int cnt = 0;
  for (int i = 0; i+1 < s.size(); i++) {
    if (isVowel(s[i]) && s[i] == s[i+1]) cnt++;
  }
  return cnt;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    string word, bestWord;
    int bestCnt = -1;
    for (int i = 0; i < n; i++) {
      cin >> word;
      int c = cnt(word);
      if (c > bestCnt) {
        bestCnt = c;
        bestWord = word;
      }
    }
    cout << bestWord << '\n';
  }
}