#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;
  for (int i = 0; i < S.size();) {
    if (i + 1 < S.size() && S[i] == 'p' && S[i + 1] == 'i') {
      i += 2;
    }
    else if (i + 1 < S.size() && S[i] == 'k' && S[i + 1] == 'a') {
      i += 2;
    }
    else if (i + 2 < S.size() && S[i] == 'c' && S[i + 1] == 'h' && S[i + 2] == 'u') {
      i += 3;
    }
    else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}