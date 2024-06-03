#include <iostream>
using namespace std;

int sumCost = 0;
int maxCost = 0;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int cost;
    cin >> cost;
    sumCost += cost;
    maxCost = max(cost, maxCost);
  }
  cout << (sumCost - maxCost);
}