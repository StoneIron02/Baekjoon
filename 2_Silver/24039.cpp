#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<bool> prime(10001, true);
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i * i <= 10000; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= 10000; j += i) {
        prime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i <= 10000; i++) {
    if (prime[i]) primes.push_back(i);
  }

  vector<long long> adj;
  for (size_t i = 0; i + 1 < primes.size(); i++) {
    long long prod = (long long) primes[i] * (long long) primes[i + 1];
    adj.push_back(prod);
  }

  sort(adj.begin(), adj.end());

  long long target = N + 1LL;
  auto it = lower_bound(adj.begin(), adj.end(), target);
  if (it == adj.end()) {
    cout << -1 << "\n";
    return 0;
  }

  long long ans = *it;
  cout << ans << "\n";

}