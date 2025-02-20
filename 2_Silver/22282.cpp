#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  long long arr[100'000];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + N, greater<>());

  int h = 0;

  for (int i = 0; i < N; ++i) {
    if (arr[i] >= i + 1) {
      h = i + 1;
    } else {
      break;
    }
  }

  cout << h;
}