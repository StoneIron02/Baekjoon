#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  int maxSum = -1;
  int maxNum = -1;
  for (int i = 0; i < m; i++) {
    int no;
    cin >> no;
    int sum = 0;
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == 'O') {
        sum += w[j];
      }
    }
    if (maxSum < sum) {
      maxSum = sum;
      maxNum = no;
    }
    if (maxSum == sum) {
      maxNum = min(maxNum, no);
    }
  }
  cout << maxNum << " " << maxSum;
}