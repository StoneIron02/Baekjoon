#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[1'000'001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int res = 0;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    cnt[num]++;
  }
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    if (cnt[num] > 0) {
      cnt[num]--;
    } else {
      res++;
    }
  }

  cout << res;
}