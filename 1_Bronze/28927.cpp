#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int sum[2];
  for (int i = 0; i < 2; i++) {
    int t, e, f;
    cin >> t >> e >> f;
    sum[i] = t * 3 + e * 20 + f * 120;
  }
  if (sum[0] > sum[1]) {
    cout << "Max";
  } else if (sum[0] < sum[1]) {
    cout << "Mel";
  } else {
    cout << "Draw";
  }
}