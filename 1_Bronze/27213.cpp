#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int m, n;
  cin >> m >> n;
  if (m < 2 || n < 2) {
    cout << m * n;
    exit(0);
  }
  long long num = 0;
  num += m * 2;
  num += n * 2;
  num -= 4;
  cout << num;
}