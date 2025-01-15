#include <iostream>
#include <algorithm>

using namespace std;

bool exist[26];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;
  for (char c : S) {
    exist[c - 'a'] = true;
  }
  if (S.size() < 26) {
    for (int i = 0; i < 26; i++) {
      if (!exist[i]) {
        cout << S;
        cout << (char)(i + 'a');
        return 0;
      }
    }
  }
  else {
    string S_prime = string(S.begin(), S.end());
    if (next_permutation(S_prime.begin(), S_prime.end())) {
      for (int i = 0; i < S.size(); i++) {
        if (S[i] != S_prime[i]) {
          S_prime = S_prime.substr(0, i + 1);
          break;
        }
      }
      cout << S_prime;
    } else {
      cout << -1;
    }
  }
}