#include <iostream>
#include <vector>
using namespace std;

int N, A, B;
bool visit[100'001];
vector<pair<int, int>> adj[100'001];

void DFS(int s, int curSum, int curMax) {
  visit[s] = true;

  if (s == B) {
    cout << (curSum - curMax);
    exit(0);
  }

  for (auto& [v, w] : adj[s]) {
    if (!visit[v]) {
      DFS(v, curSum + w, max(curMax, w));
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> A >> B;
  for (int i = 0; i < N - 1; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }

  DFS(A, 0, 0);
}