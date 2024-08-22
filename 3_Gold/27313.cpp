#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<long long> times;

int find(int left, int right) {
  if (left > right) {
    return right;
  }

  int mid = (left + right) / 2;
  long long sumTime = 0;
  for (int i = mid - 1; i >= 0; i -= K) {
    sumTime += times[i];
  }

  if (sumTime <= M) {
    return find(mid + 1, right);
  } else {
    return find(left, mid - 1);
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    long long t;
    cin >> t;
    if (t <= M) {
      times.push_back(t);
    }
  }
  sort(times.begin(), times.end());
  if (times.empty()) {
    cout << 0;
    exit(0);
  }
  cout << find(1, times.size());
}
