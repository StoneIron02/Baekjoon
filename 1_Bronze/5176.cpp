#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int k;
  cin >> k;
  while (k--) {
    int p, m;
    cin >> p >> m;
    vector<bool> exist(m + 1, 0);
    int cnt = 0;
    while (p--) {
      int num;
      cin >> num;
      if (exist[num]) cnt++;
      else exist[num] = true;
    }
    cout << cnt << "\n";
  }
}
