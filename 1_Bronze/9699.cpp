#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int max_value = -1;
    for (int j = 0; j < 5; j++) {
      int val;
      cin >> val;
      max_value = max(max_value, val);
    }
    cout << "Case #" << i << ": " << max_value << "\n";
  }
}