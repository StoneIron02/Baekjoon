#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  long long K, sumCos = 0;
  cin >> N >> K;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    sumCos += arr[i];
  }

  long long curDist = 0;
  long long curCos = 1;
  if (K <= sumCos) {
    int i = 0;
    while (curDist + arr[i] <= K) {
      curDist += arr[i];
      curCos++;
      i++;
    }
  }
  if (K >= sumCos) {
    curDist = sumCos;
    curCos = N;
    reverse(arr.begin(), arr.end());
    int i = 0;
    while (curDist + arr[i] <= K) {
      curDist += arr[i];
      curCos--;
      i++;
    }
  }
  cout << curCos;
}