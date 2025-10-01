#include <iostream>
#include <vector>
using namespace std;

int N;
long long K;
vector<long long> A;
long long cnt = 0;
pair<long long,long long> res = {-1, -1};

void swap(int i, int j) {
  cnt++;
  if (cnt == K) {
    res = {min(A[i], A[j]), max(A[i], A[j])};
  }
  swap(A[i], A[j]);
}

void heapify(int k, int n) {
  int left = 2 * k;
  int right = 2 * k + 1;
  int smaller;

  if (right <= n) {
    smaller = (A[left] < A[right]) ? left : right;
  } else if (left <= n) {
    smaller = left;
  } else return;

  if (A[smaller] < A[k]) {
    swap(k, smaller);
    heapify(smaller, n);
  }
}

void build_min_heap(int n) {
  for (int i = n / 2; i >= 1; i--) {
    heapify(i, n);
  }
}

void heap_sort(int n) {
  build_min_heap(n);
  for (int i = n; i >= 2; i--) {
    swap(1, i);
    heapify(1, i - 1);
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  A.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  heap_sort(N);

  if (res.first == -1) cout << -1 << "\n";
  else cout << res.first << " " << res.second << "\n";
}
