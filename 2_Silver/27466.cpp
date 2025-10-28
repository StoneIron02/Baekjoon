#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  string S;
  cin >> N >> M >> S;
  string vowels = "AEIOU";
  unordered_set<char> v(vowels.begin(), vowels.end());

  int idx_c = -1, idx_a2 = -1, idx_a1 = -1;

  for (int i = N - 1; i >= 0; i--) {
    if (idx_c == -1 && !v.count(S[i])) idx_c = i;
    else if (idx_c != -1 && idx_a2 == -1 && S[i] == 'A') idx_a2 = i;
    else if (idx_a2 != -1 && idx_a1 == -1 && S[i] == 'A') {
      idx_a1 = i;
      break;
    }
  }

  if (idx_c == -1 || idx_a2 == -1 || idx_a1 == -1 || idx_a1 - (M - 3) < 0) {
    cout << "NO\n";
    return 0;
  }

  string T;
  for (int i = idx_a1 - (M - 3); T.size() < M - 3; i++)
    T.push_back(S[i]);
  T.push_back('A');
  T.push_back('A');
  T.push_back(S[idx_c]);

  if (T.size() != M) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n" << T << "\n";
}