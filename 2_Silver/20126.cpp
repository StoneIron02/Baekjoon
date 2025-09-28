#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

pii arr[100'000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M, S;
  cin >> N >> M >> S;
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    arr[i] = {x, y};
  }
  sort(arr, arr + N);

  int latest = 0;
  for (int i = 0; i < N; ++i) {
    auto [x, y] = arr[i];
    if (x - latest >= M) {
      cout << latest << "\n";
      return 0;
    }
    latest = max(latest, x + y);
  }
  if (S - latest >= M) {
    cout << latest << "\n";
  } else {
    cout << -1 << "\n";
  }
}