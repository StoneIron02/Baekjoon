#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, S;
  cin >> N >> S;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int left = 0, right = N - 1;
  int count = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];

    if (sum == S) {
      count++;
      left++;
      right--;
    }
    else if (sum < S) {
      left++;
    }
    else {
      right--;
    }
  }

  cout << count << '\n';
}