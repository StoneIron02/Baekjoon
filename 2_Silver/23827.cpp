#include <iostream>
using namespace std;

long long arr[500'001];
long long sum[500'001];
constexpr long long MOD = 1'000'000'007;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
    sum[i] = (sum[i - 1] + arr[i]) % MOD;
  }

  if (N == 2) {
    cout << sum[N];
    exit(0);
  }

  long long res = 0;
  for (int i = 1; i < N; ++i) {
    res = (res + arr[i] * (sum[N] - sum[i]) % MOD) % MOD;
  }
  cout << res;
}
