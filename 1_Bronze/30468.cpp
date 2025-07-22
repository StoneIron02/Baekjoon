#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int STR, DEX, INT, LUK, N;
  cin >> STR >> DEX >> INT >> LUK >> N;

  int sum = STR + DEX + INT + LUK;
  int target = 4 * N;

  int res = max(0, target - sum);
  cout << res;
}