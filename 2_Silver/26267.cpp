#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  unordered_map<long long, long long> mp;

  long long res = 0;
  for (int i = 0; i < N; i++) {
    long long X, T, C;
    cin >> X >> T >> C;
    mp[X - T] += C;
    res = max(res, mp[X - T]);
  }

  cout << res;
}