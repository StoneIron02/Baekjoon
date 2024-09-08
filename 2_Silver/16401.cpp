#include <iostream>

using namespace std;

int M, N;
long long len[1'000'000];
long long L = 1'000'000'000;

long long getCnt(long long val) {
  long long cnt = 0;
  for (int i = 0; i < N; i++) {
    cnt += len[i] / val;
  }
  return cnt;
}

long long find(long long left, long long right) {
  if (left + 1 >= right) return left;
  long long mid = (left + right) / 2;
  long long cnt = getCnt(mid);

  if (cnt < M) {
    return find(left, mid);
  } else {
    return find(mid, right);
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> M >> N;
  for (int i = 0; i < N; i++) {
    cin >> len[i];
  }
  long long sz = find(1, L);
  if (getCnt(sz) < M) {
    cout << 0;
  } else {
    cout << sz;
  }
}