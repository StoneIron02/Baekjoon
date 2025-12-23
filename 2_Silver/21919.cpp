#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];

  const int MAX = 1'000'000;
  vector<bool> isPrime(MAX + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= MAX; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX; j += i)
        isPrime[j] = false;
    }
  }

  unsigned long long lcm = 1;
  bool found = false;

  for (int x : A) {
    if (isPrime[x]) {
      found = true;
      unsigned long long g = gcd(lcm, static_cast<unsigned long long>(x));
      lcm = lcm / g * x;
    }
  }

  if (!found)
    cout << -1;
  else
    cout << lcm;
}
