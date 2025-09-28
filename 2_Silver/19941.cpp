#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, K;
  cin >> N >> K;
  string str;
  cin >> str;

  vector flag(N, false);
  int result = 0;
  for (int i = 0; i < N; i++) {
    if (str[i] == 'P') {
      for (int j = max(0, i - K); j <= min(N - 1, i + K); j++) {
        if (str[j] == 'H' && !flag[j]) {
          flag[j] = true;
          result++;
          break;
        }
      }
    }
  }

  cout << result;
}