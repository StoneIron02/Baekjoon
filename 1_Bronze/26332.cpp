#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  while (N--) {
    int C, P;
    cin >> C >> P;
    cout << C << " " << P << "\n";
    cout << (C - 1) * (P - 2) + P << "\n";
  }
}