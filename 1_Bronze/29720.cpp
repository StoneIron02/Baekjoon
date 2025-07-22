#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;

  int minVal = max(0, N - M * K);
  int maxVal = max(0, N - 1 - M * (K - 1));

  cout << minVal << " " << maxVal;
}