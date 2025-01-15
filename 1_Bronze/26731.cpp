#include <iostream>

using namespace std;

bool exist[26];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  for (char c : str) {
    exist[c - 'A'] = true;
  }

  for (int i = 0; i < 26; i++) {
    if (!exist[i]) {
      cout << (char)(i + 'A');
      return 0;
    }
  }
}