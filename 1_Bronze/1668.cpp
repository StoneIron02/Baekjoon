#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int result1 = 1, result2 = 1;
  int cur1 = arr[0];
  for (int i = 1; i < n; i++) {
    if (cur1 < arr[i]) {
      cur1 = arr[i];
      result1++;
    }
  }
  int cur2 = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (cur2 < arr[i]) {
      cur2 = arr[i];
      result2++;
    }
  }

  cout << result1 << "\n" << result2;
}