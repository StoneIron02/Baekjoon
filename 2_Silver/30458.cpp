#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cntL[26], cntR[26], tot[26];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  string S;
  cin >> N >> S;

  int mid = N / 2;
  string L = S.substr(0, mid);
  string R = S.substr(N - mid);

  for (char c : L) cntL[c - 'a']++;
  for (char c : R) cntR[c - 'a']++;

  for (int i = 0; i < 26; i++) tot[i] = cntL[i] + cntR[i];

  int oddCount = 0;
  for (int i = 0; i < 26; i++)
    if (tot[i] % 2) oddCount++;

  if (oddCount > (N % 2)) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
}