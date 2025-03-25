#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, X;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  cin >> X;

  long long sum = 0;
  int count = 0;
  for (int num : A) {
    if (gcd(num, X) == 1) {
      sum += num;
      count++;
    }
  }
  cout << fixed << setprecision(6) << (double)sum / count;
}