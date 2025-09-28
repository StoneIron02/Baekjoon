#include <iostream>
using namespace std;

int arr[1005];
int block[1005];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  int F;
  cin >> F;
  for (int i = 0; i < F; ++i) {
    int X, Y;
    cin >> X >> Y;
    arr[X] += Y;
  }

  for (int i = 1; i <= N; ++i) {
    block[i] = 1 + arr[i];
  }

  int res = 0;
  int i = 1;
  while (i <= N) {
    int t = 0;
    int foot = 0;
    while (i <= N) {
      int used = 0;
      while (i <= N && used + block[i] <= K) {
        used += block[i];
        ++i;
      }
      if (used == 0 && i <= N) {
        ++res;
        ++i;
        continue;
      }
      ++res;
    }
  }

  cout << res;
}