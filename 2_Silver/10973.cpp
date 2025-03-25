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

  if (prev_permutation(arr.begin(), arr.end())) {
    for (int i = 0; i < N; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  } else {
    cout << "-1\n";
  }
}