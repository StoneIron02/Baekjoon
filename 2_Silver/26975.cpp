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
  vector<long long> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  long long maxVal = 0;
  long long maxArrVal = 0;

  for (int i = 0; i < N; i++) {
    long long res = arr[i] * (N - i);

    if (res > maxVal) {
      maxVal = res;
      maxArrVal = arr[i];
    }
  }

  cout << maxVal << " " << maxArrVal << endl;
}