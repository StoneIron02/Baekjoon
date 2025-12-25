#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string key, encrypted;
  int K;
  cin >> key >> K >> encrypted;

  vector<bool> used(26, false);
  for (char c : key)
    used[c - 'A'] = true;

  vector<char> remain;
  for (int i = 0; i < 26; ++i) {
    if (!used[i])
      remain.push_back('A' + i);
  }

  vector<char> lower(26, 0);
  int pos = K - 1;

  for (char c : key) {
    lower[pos] = c;
    pos = (pos + 1) % 26;
  }

  for (char c : remain) {
    lower[pos] = c;
    pos = (pos + 1) % 26;
  }

  vector<char> decrypt(26);
  for (int i = 0; i < 26; ++i) {
    decrypt[lower[i] - 'A'] = 'A' + i;
  }

  for (char &c : encrypted) {
    c = decrypt[c - 'A'];
  }

  cout << encrypted;
}
