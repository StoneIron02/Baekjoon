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
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  int maxBrand = arr.back();
  int ways = 0;

  for (int K = 1; K <= maxBrand; K++) {
    int cnt = 1;
    for (int brand = 1; brand <= K; brand++) {
      cnt *= count(arr.begin(), arr.end(), brand);
    }
    ways += cnt;
  }

  cout << ways << endl;
}