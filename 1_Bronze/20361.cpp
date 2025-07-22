#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, X, K;
  cin >> N >> X >> K;
  while (K--) {
    int A, B;
    cin >> A >> B;
    if (X == A) X = B;
    else if (X == B) X = A;
  }
  cout << X;
}