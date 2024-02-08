#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    if (x < y) {
      cout << "NO BRAINS\n";
    } else {
      cout << "MMM BRAINS\n";
    }
  }
}