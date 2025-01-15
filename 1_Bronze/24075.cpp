#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;
  cout << max(A + B, A - B) << "\n" << min(A + B, A - B);
}