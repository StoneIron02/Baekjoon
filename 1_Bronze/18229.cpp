#include <iostream>
using namespace std;

int A[101][101];
int reach[101];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      cin >> A[i][j];

  for (int j = 0; j < M; ++j) {
    for (int i = 0; i < N; ++i) {
      reach[i] += A[i][j];
      if (reach[i] >= K) {
        cout << i + 1 << " " << j + 1;
        return 0;
      }
    }
  }
}