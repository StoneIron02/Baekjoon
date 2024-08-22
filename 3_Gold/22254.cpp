#include <iostream>
#include <queue>
using namespace std;

int N;
long long X;
long long times[100'001];

int find(int left, int right) {
  if (left == right) {
    return left;
  }

  int mid = (left + right) / 2;
  priority_queue<long long, vector<long long>, greater<>> pq;
  for (int i = 0; i < mid; i++) {
    pq.push(0);
  }
  for (int i = 1; i <= N; i++) {
    long long top = pq.top();
    pq.pop();
    pq.push(top + times[i]);
  }
  while (pq.size() > 1) {
    pq.pop();
  }
  long long result = pq.top();

  if (result > X) {
    return find(mid + 1, right);
  } else {
    return find(left, mid);
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> X;
  for (int i = 1; i <= N; i++) {
    cin >> times[i];
  }
  cout << find(1, 100'000);
}
