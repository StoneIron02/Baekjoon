#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[51], B[51];
int DP[51][51];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (int j = 1; j <= N; j++) {
    cin >> B[j];
  }

  sort(A + 1, A + N + 1, greater<>());
  sort(B + 1, B + N + 1, greater<>());

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (A[i] > B[j]) {
        DP[i][j] = max(DP[i - 1][j - 1] + 2, DP[i - 1][j]);
      }
      else if (A[i] == B[j]) {
        DP[i][j] = max(DP[i - 1][j - 1] + 1, DP[i - 1][j]);
      }
      else {
        DP[i][j] = DP[i - 1][j];
      }
    }
  }

  cout << DP[N][N];
}
