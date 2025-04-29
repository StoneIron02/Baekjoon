#include <iostream>
#include <queue>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    pq.push(num);
  }
  long long sum = 0;
  while (pq.size() > 1) {
    int num1 = pq.top();
    pq.pop();
    int num2 = pq.top();
    pq.pop();
    int res = num1 + num2;
    sum += res;
    pq.push(res);
  }
  cout << sum;
}
