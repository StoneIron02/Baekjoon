#include <iostream>
#include <queue>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int my;
  cin >> my;
  if (n == 1) {
    cout << 0;
    exit(0);
  }
  int cnt = 0;
  priority_queue<int> pq;
  for (int i = 1; i < n; i++) {
    int num;
    cin >> num;
    pq.push(num);
  }
  while (my <= pq.top()) {
    int top = pq.top();
    pq.pop();
    pq.push(top - 1);
    my++;
    cnt++;
  }
  cout << cnt;
}