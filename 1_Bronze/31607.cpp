#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int A, B, C;
  cin >> A >> B >> C;
  if (A + B == C || B + C == A || C + A == B) {
    cout << 1;
  } else {
    cout << 0;
  }
}