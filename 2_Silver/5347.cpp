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
    long long a, b;
    cin >> a >> b;
    if (a < b) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    cout << lcm(a, b) << "\n";
  }
}