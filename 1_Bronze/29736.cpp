#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;
  int K, X;
  cin >> K >> X;
  int L = K - X;
  int R = K + X;
  if (R < A || B < L) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  L = max(L, A);
  R = min(R, B);
  cout << R - L + 1;
}