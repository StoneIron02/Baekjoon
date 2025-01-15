#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  int cnt = 0;
  for (int i = 0; i < 5; i++) {
    int n;
    cin >> n;
    if (n == T) cnt++;
  }
  cout << cnt;
}