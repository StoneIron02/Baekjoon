#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int A, K;
  cin >> A >> K;

  queue<int> que;
  unordered_map<int, int> dist;
  que.push(A);
  dist[A] = 0;

  while (!que.empty()) {
    int num = que.front();
    que.pop();

    if (num == K) {
      cout << dist[num];
      exit(0);
    }


    int next1 = num + 1;
    if (!dist.contains(next1)) {
      dist[next1] = dist[num] + 1;
      que.push(next1);
    }

    int next2 = num * 2;
    if (next2 > 1'000'000) continue;
    if (!dist.contains(next2)) {
      dist[next2] = dist[num] + 1;
      que.push(next2);
    }
  }
}
