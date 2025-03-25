#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;

  int cnt1 = 0, cnt2 = 0;

  for (int i = 0; i < n; i++) {
    int coin;
    cin >> coin;
    if (coin == 0) cnt1++;
    else cnt2++;
  }

  cout << min(cnt1, cnt2) << endl;
}