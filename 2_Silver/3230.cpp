#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  deque<int> rankFirst = {0};
  deque<int> rankSecond = {0};
  for (int i = 1; i <= N; i++) {
    int rank;
    cin >> rank;
    rankFirst.insert(rankFirst.begin() + rank, i);
  }
  reverse(rankFirst.begin() + 1, rankFirst.end());
  for (int i = 1; i <= M; i++) {
    int j = rankFirst[N - M + i];
    int rank;
    cin >> rank;
    rankSecond.insert(rankSecond.begin() + rank, j);
  }

  for (int i = 1; i <= 3; i++) {
    cout << rankSecond[i] << "\n";
  }
}
