#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int a, d, k;
  cin >> a >> d >> k;
  if ((k - a) % d == 0) {
    int n = (k - a) / d + 1;
    if (n >= 1)
      cout << n << endl;
    else
      cout << "X" << endl;
  } else {
    cout << "X" << endl;
  }
}
