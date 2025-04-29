#include <iostream>
#include <cmath>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  double N, B, M;
  while (cin >> N >> B >> M) {
    int year = 0;
    while (N < M) {
      N += N * (B / 100);
      year++;
    }
    cout << year << "\n";
  }
}
