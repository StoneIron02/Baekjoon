#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;

    long long res = 0;
    for (int i = 0; i < N; ++i) {
      int c;
      cin >> c;
      res += c / K;
    }
    cout << res << "\n";
  }
}