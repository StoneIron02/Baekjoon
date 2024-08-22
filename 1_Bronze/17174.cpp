#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;
  int sum = 0;
  while (n > 0) {
    sum += n;
    n /= m;
  }
  cout << sum;
}
