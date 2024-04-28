#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string a, b;
  while (getline(cin,a), getline(cin,b)) {
    int cntA[26], cntB[26];
    for (int i = 0; i < 26; i++) {
      cntA[i] = 0;
      cntB[i] = 0;
    }
    for (char c : a) {
      cntA[c - 'a']++;
    }
    for (char c : b) {
      cntB[c - 'a']++;
    }

    string result;
    for (int i = 0; i < 26; i++) {
      int minCnt = min(cntA[i], cntB[i]);
      while (minCnt--) {
        result += (char)(i + 'a');
      }
    }
    cout << result << "\n";
  }
}