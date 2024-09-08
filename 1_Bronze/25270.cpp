#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  if (n < 100) {
    cout << 99;
  } else {
    int num99 = n - (n % 100) + 99;
    int num99minus = num99 - 100;
    int dist1 = abs(n - num99);
    int dist2 = abs(n - num99minus);
    if (dist1 <= dist2) {
      cout << num99;
    } else {
      cout << num99minus;
    }
  }
}