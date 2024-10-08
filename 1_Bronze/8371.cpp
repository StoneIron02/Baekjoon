#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) cnt++;
  }
  cout << cnt;
}
