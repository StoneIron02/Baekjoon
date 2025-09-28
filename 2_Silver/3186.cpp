#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int K, L, N;
  cin >> K >> L >> N;
  string str;
  cin >> str;

  vector<int> flushes;
  int ones = 0;
  int zeros = 0;
  bool inUse = false;

  for (int t = 1; t <= N; t++) {
    char c = str[t-1];
    if (c == '1') {
      ones++;
      if (!inUse && ones >= K) {
        inUse = true;
        zeros = 0;
      } else if (inUse) {
        zeros = 0;
      }
    } else {
      ones = 0;
      if (inUse) {
        zeros++;
        if (zeros == L) {
          flushes.push_back(t);
          inUse = false;
          zeros = 0;
        }
      }
    }
  }

  if (inUse) {
    flushes.push_back(N + (L - zeros));
  }

  if (flushes.empty()) {
    cout << "NIKAD\n";
  } else {
    for (int f : flushes) cout << f << "\n";
  }
}