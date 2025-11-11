#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<vector<int>> S(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> S[i][j];
    }
  }

  vector<int> A(N);
  A[0] = (S[0][1] + S[0][2] - S[1][2]) / 2;
  for (int i = 1; i < N; ++i) {
    A[i] = S[0][i] - A[0];
  }

  for (int i = 0; i < N; ++i) {
    cout << A[i] << " ";
  }
}
