#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  string P = "driip";
  reverse(P.begin(), P.end());
  bool flag = true;
  for (int i = 0; i < P.size(); i++) {
    if (S[i] != P[i]) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "cute";
  } else {
    cout << "not cute";
  }
}