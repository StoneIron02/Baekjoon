#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long long N, M;
  int T, S;
  cin >> N >> M;
  cin >> T >> S;

  long long cnt_home = (N - 1) / 8;
  long long time_home = N + cnt_home * S;

  long long cnt_lib = (M - 1) / 8;
  long long time_lib = T + M + cnt_lib * (2LL * T + S);

  if (time_home < time_lib) {
    cout << "Zip\n" << time_home;
  } else {
    cout << "Dok\n" << time_lib;
  }
}