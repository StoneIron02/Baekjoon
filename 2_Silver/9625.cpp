#include <iostream>

using namespace std;

long long cnt[46][2];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int K;
  cin >> K;
  cnt[0][0] = 1;
  for (int i = 1; i <= K; i++) {
    cnt[i][1] = cnt[i - 1][0] + cnt[i - 1][1];
    cnt[i][0] = cnt[i - 1][1];
  }
  cout << cnt[K][0] << " " << cnt[K][1];
}