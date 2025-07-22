#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> tmp;
long long count_write = 0;

void merge(vector<int>& A, int p, int q, int r) {
  int i = p, j = q + 1, t = 0;

  while (i <= q && j <= r) {
    if (A[i] <= A[j]) tmp[t++] = A[i++];
    else tmp[t++] = A[j++];
  }

  while (i <= q) tmp[t++] = A[i++];
  while (j <= r) tmp[t++] = A[j++];

  i = p; t = 0;
  while (i <= r) {
    A[i++] = tmp[t++];
    count_write++;
    if (count_write == K) {
      for (int k = 0; k < N; ++k) {
        cout << A[k] << ' ';
      }
      exit(0);
    }
  }
}

void merge_sort(vector<int>& A, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  vector<int> A(N);
  tmp.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  merge_sort(A, 0, N - 1);

  cout << -1;
}