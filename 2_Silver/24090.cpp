#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int cnt;

int partition(vector<int>& A, int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j <= r - 1; j++) {
    if (A[j] <= x) {
      ++i;
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
      ++cnt;
      if (cnt == K) {
        cout << min(A[i], A[j]) << " " << max(A[i], A[j]);
        exit(0);
      }
    }
  }
  if (i + 1 != r) {
    int tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp;
    ++cnt;
    if (cnt == K) {
      cout << min(A[i + 1], A[r]) << " " << max(A[i + 1], A[r]);
      exit(0);
    }
  }
  return i + 1;
}

void quick_sort(vector<int>& A, int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quick_sort(A, p, q - 1);
    quick_sort(A, q + 1, r);
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  quick_sort(A, 0, N - 1);
  cout << -1;
}
