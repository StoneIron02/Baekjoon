#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int K;
  cin >> K;
  for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    a = min(a, N - a + 1);
    b = min(b, N - b + 1);
    int m = min(a, b);
    cout << ((m - 1) % 3) + 1 << "\n";
  }
}