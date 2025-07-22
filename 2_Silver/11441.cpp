#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> sum(N + 1);
  for (int i = 1; i <= N; i++) {
    int num;
    cin >> num;
    sum[i] = sum[i - 1] + num;
  }
  int M;
  cin >> M;
  while (M--) {
    int i, j;
    cin >> i >> j;
    cout << sum[j] - sum[i - 1] << "\n";
  }
}