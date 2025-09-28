#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long N;
  cin >> N;

  if (N <= 1) {
    cout << 1;
    return 0;
  }

  if (N % 2 == 0) {
    if (N == 2) cout << 4;
    else cout << N;
  } else {
    cout << N + 1;
  }
}