#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string A, B;
  cin >> A >> B;
  for (int i = 1; i <= A.size(); i++) {
    dp[i][0] = i;
  }
  for (int j = 1; j <= B.size(); j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= A.size(); i++) {
    for (int j = 1; j <= B.size(); j++) {
      dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1]
        : min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
    }
  }
  cout << dp[A.size()][B.size()];

}
