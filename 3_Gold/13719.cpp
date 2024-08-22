#include <iostream>
#include <deque>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  deque<int> dq;
  while (n--) {
    int num;
    cin >> num;
    dq.push_back(num);
  }
  int cnt = 0;
  while (!dq.empty()) {
    if (dq.size() == 1) {
      dq.pop_back();
      continue;
    }
    if (dq.front() == dq.back()) {
      dq.pop_front();
      dq.pop_back();
      continue;
    }
    if (dq.front() < dq.back()) {
      int n1, n2;
      n1 = dq.front();
      dq.pop_front();
      n2 = dq.front();
      dq.pop_front();
      int sum = n1 + n2;
      dq.push_front(sum);
      cnt++;
    } else {
      int n1, n2;
      n1 = dq.back();
      dq.pop_back();
      n2 = dq.back();
      dq.pop_back();
      int sum = n1 + n2;
      dq.push_back(sum);
      cnt++;
    }
  }
  cout << cnt;
}
