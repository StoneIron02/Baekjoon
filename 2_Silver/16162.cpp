#include <iostream>

using namespace std;

int arr[20001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  int A, D;
  cin >> N >> A >> D;

  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  int cur = A;
  int cnt = 0;

  for (int i = 0; i < N; ++i) {
    if (arr[i] == cur) {
      ++cnt;
      cur += D;
    }
  }

  cout << cnt;
}