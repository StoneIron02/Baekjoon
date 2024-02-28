#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int sel[7];
int sum;

void backtracking(int cur, int start) {
  if (cur == 7) {
    if (sum == 100) {
      for (int i : sel) {
        cout << arr[i] << "\n";
      }
      exit(0);
    }
    return;
  }
  for (int i = start; i < 9; i++) {
    sel[cur] = i;
    sum += arr[i];
    backtracking(cur + 1, i + 1);
    sum -= arr[i];
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (int & i : arr) {
    cin >> i;
  }

  sort(arr, arr + 9);

  backtracking(0, 0);
}