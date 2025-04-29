#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int result = 0;

    for (long long i = 5; i <= N; i *= 5) {
      result += N / i;
    }
    cout << result << '\n';
  }
}
