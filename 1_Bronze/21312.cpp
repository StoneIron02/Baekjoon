#include <iostream>
#include <queue>

using namespace std;

struct compare {
  bool operator()(int a, int b) {
    if (a % 2 == b % 2) {
      return a < b;
    }
    return (a % 2 < b % 2);
  }
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;
  priority_queue<int, vector<int>, compare> pq;
  pq.push(a);
  pq.push(b);
  pq.push(c);
  pq.push(a * b);
  pq.push(b * c);
  pq.push(c * a);
  pq.push(a * b * c);
  cout << pq.top();
}