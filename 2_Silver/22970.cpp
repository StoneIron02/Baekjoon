#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int arr[5000];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int maxLen = 1;

  for (int i = 0; i < N; i++) {
    int left = i, right = i;
    while (left - 1 >= 0 && arr[left - 1] < arr[left])
      left--;
    while (right + 1 < N && arr[right] > arr[right + 1])
      right++;
    int len = right - left + 1;
    maxLen = max(maxLen, len);
  }

  cout << maxLen;
}