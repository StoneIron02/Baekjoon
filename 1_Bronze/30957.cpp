#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);


  int N;
  cin >> N;

  string s;
  cin >> s;

  int B = 0, S = 0, A = 0;
  for (char c : s) {
    if (c == 'B') B++;
    else if (c == 'S') S++;
    else A++;
  }

  int mx = max({B, S, A});

  int cnt = 0;
  if (B == mx) cnt++;
  if (S == mx) cnt++;
  if (A == mx) cnt++;

  if (cnt == 3) {
    cout << "SCU";
  } else {
    if (B == mx) cout << 'B';
    if (S == mx) cout << 'S';
    if (A == mx) cout << 'A';
  }
}
