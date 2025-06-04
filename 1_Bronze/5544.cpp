#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

pii score[101];
int res[101];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    score[i].second = i;
  }
  for (int i = 0; i < N * (N - 1) / 2; ++i) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (C > D) {
      score[A].first += 3;
    } else if (C < D) {
      score[B].first += 3;
    } else {
      ++score[A].first;
      ++score[B].first;
    }
  }

  int before_score = 999;
  sort(score + 1, score + N + 1, greater());
  for (int i = 1; i <= N; ++i) {
    if (score[i].first != before_score) {
      res[score[i].second] = i;
      before_score = score[i].first;
    } else {
      res[score[i].second] = res[score[i - 1].second];
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << res[i] << "\n";
  }
}
