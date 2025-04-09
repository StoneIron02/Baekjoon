#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long K, N;
  cin >> K >> N;

  if (N <= 1) {
    cout << -1;
    return 0;
  }

  long long a = K * N;
  long long b = N - 1;

  long long X = a / b;
  if (a % b != 0) {
    X++;
  }

  cout << X;
}