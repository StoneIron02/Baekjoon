#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int sum = 0;
  int t;
  cin >> t;
  sum += t;
  for (int i = 1; i < n; i++) {
    sum += 8;
    cin >> t;
    sum += t;
  }
  cout << (sum / 24) << " " << (sum % 24);
}