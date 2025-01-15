#include <iostream>
#include <climits>

using namespace std;

int cost[18];
int people[18][13];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, b, h, w;
  cin >> n >> b >> h >> w;

  for (int i = 0; i < h; i++) {
    cin >> cost[i];
    for (int j = 0; j < w; j++) {
      cin >> people[i][j];
    }
  }

  int minCost = INT_MAX;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (people[i][j] >= n && n * cost[i] <= b) {
        minCost = min(minCost, n * cost[i]);
      }
    }
  }
  if (minCost == INT_MAX) {
    cout << "stay home";
  } else {
    cout << minCost;
  }
}