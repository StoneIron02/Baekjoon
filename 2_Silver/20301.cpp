#include <deque>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K, M;
  cin >> N >> K >> M;
  deque<int> deq;
  for (int i = 1; i <= N; i++)
    deq.push_back(i);
  
  bool flag = true;
  int cnt = 0;
  while (!deq.empty()) {
    if (flag) {
      for (int i = 1; i < K; i++) {
        deq.push_back(deq.front());
        deq.pop_front();
      }
      cout << deq.front() << '\n';
      deq.pop_front();
    } else {
      for (int i = 1; i < K; i++) {
        deq.push_front(deq.back());
        deq.pop_back();
      }
      cout << deq.back() << '\n';
      deq.pop_back();
    }
    cnt++;
    if (cnt == M) {
      cnt = 0;
      flag = !flag;
    }
  }
}
