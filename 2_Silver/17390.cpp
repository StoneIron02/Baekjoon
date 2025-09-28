#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (auto& i : A) cin >> i;
  sort(A.begin(), A.end());

  vector<int> sum(N);
  sum.insert(sum.begin(), 0);
  for (int i = 1; i < sum.size(); ++i) {
    sum[i] = sum[i - 1] + A[i - 1];
  }
  while (Q--) {
    int L, R;
    cin >> L >> R;
    cout << sum[R] - sum[L - 1] << '\n';
  }
}