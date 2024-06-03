#include <iostream>
using namespace std;

int cnt[26];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  getline(cin, str);
  for (char c : str) {
    if (c >= 'a' && c <= 'z') {
      cnt[c - 'a']++;
    }
    else if (c >= 'A' && c <= 'Z') {
      cnt[c - 'A']++;
    }
  }
  for (int i = 0; i < 26; i++) {
    cout << (char)(i + 'A') << " | ";
    for (int j = 0; j < cnt[i]; j++) {
      cout << "*";
    }
    cout << "\n";
  }
}