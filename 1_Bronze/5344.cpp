#include <iostream>
#include <numeric>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
  }
}